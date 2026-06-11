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

int dp[444][444];

void solve() {
        int n; cin >> n;
        vector<int> v(n), sum(n+ 2, 0);

        for (auto& i: v) cin >> i;

        for (int i= 1; i<= n; i++) sum[i]= sum[i- 1]+ v[i- 1];

        memset(dp, -1, sizeof(dp));

        function<int(int, int)> calc= [&](int i, int j)->int{
                if (i== j) return 0;
                if (j- i== 1) {
                        return v[i]+ v[j];
                }

                int &ret= dp[i][j];
                if(ret!= -1) return ret;
                ret= 1e18;

                for (int k= i; k< j; k++) {
                        ret= min(ret, calc(i, k)+ calc(k+ 1, j)+ (sum[j+ 1]- sum[i]));

                }
                return ret;
        };
        cout << calc(0, n- 1);
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
