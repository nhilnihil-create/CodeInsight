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

const int N= 200001;

void solve() {
        int n, m, q; cin >> n>> m>> q;

        vector<int> v(n+ m), up(n+ m, 1e18), down(n+ m, 1e18);

        map<int, int> mp1, mp2;

        for (int i= 0; i< n; i++) {
                int x; cin >> x;
                v[i]= x;
                mp1[x]++;
        }

        for (int i= 0; i< m; i++) {
                int x; cin >> x;
                v[i+ n]= x;
                mp2[x]++;
        }

        sort(all(v));

        int cnt2= -1, cnt1= -1;

        for (int i= 0; i< n+ m; i++) {
                if (mp1.count(v[i])) {
                        cnt1= v[i];
                        if (cnt2!= -1) {
                                down[i]= v[i]- cnt2;
                        }
                } else {
                        cnt2= v[i];
                        if (cnt1!= -1) {
                                down[i]= v[i]- cnt1;
                        }
                }
        }

        cnt1= cnt2= -1;

        for (int i= n+ m- 1; i>= 0; i--) {
                if (mp1.count(v[i])) {
                        cnt1= v[i];
                        if (cnt2!= -1) {
                                up[i]= cnt2- v[i];
                        }
                } else {
                        cnt2= v[i];
                        if (cnt1!= -1) {
                                up[i]= cnt1- v[i];
                        }
                }
        }

        for (int i= 0; i< n+ m; i++) {
                up[i]= min(up[i], down[i]);
        }
        for (int i= 0; i< q; i++) {
                int x; cin>> x;
                int pos= lower_bound(all(v), x)- v.begin();
                if (pos== n+ m) {
                        pos--;
                        cout << (x- v[pos])+ up[pos]<< "\n";
                } else if (pos== 0){
                        cout << (v[pos]- x)+ up[pos]<< "\n";
                }else {
                        cout << min(v[pos]- x+ up[pos], x- v[pos- 1]+ up[pos- 1])<< "\n";
                }

        }
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
