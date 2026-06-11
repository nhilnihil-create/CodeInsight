#include <bits/stdc++.h>
using namespace std;
#define pr(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define all(v) (v).begin(), (v).end()
#define int long long
#define sz(v) (int)(v).size()
#define mod 1000000007 // ((a- b)% mod+ mod)% mod

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int dp[22][1<< 21];

void solve() {
        int n; cin >> n;
        vector<vector<int>> v(n);

        for (auto& i: v) {
                vector<int> vv(n);
                for (auto& x: vv) cin >> x;
                i= vv;
        }

        int val= (1<< n)- 1;
        memset(dp, -1, sizeof(dp));

        auto setbit= [=](int idx, int &msk) {
                msk= (msk| 1<< idx);
        };

        auto clearbit= [=](int idx, int &msk) {
                msk= msk & ~(1 << idx);
        };

        function<int(int, int)> calc= [&](int idx, int msk)->int{
                if (idx== n) {
                        if (msk!= val) return 0;
                        else return 1;
                }

                int &ret= dp[idx][msk];
                if (ret!= -1) return ret;
                ret= 0;

                for (int j= 0; j< n; j++) {
                        if (v[idx][j]&& ((msk&(1<< j))== 0)) {
                                setbit(j, msk);
                                ret= (ret+ calc(idx+ 1, msk))% mod;
                                clearbit(j, msk);
                        }
                }

                return ret% mod;
        };
        cout << calc(0, 0)% mod;
}

int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        //cin >> T;
        while ( T-- ) {
                solve();
        }
return 0;
}
