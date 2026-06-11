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

const int N= 501;
const int M= 31;

int ar[N][N];
int cost[M][M];
int ne[M][N];
int v[N][N];

void solve() {

        int n, m; cin >> n>> m;

        for (int i= 1; i< N; i++)
                for (int j= 1; j< N; j++) v[i- 1][j- 1]= (i+ j)% 3;

        for (int i= 1; i<= m; i++)
                for (int j= 1; j<= m; j++) cin >> cost[i][j];

        for (int i= 0; i< n; i++)
                for (int j= 0; j< n; j++) cin >> ar[i][j];

        for (int i= 0; i< n; i++)
                for (int j= 0; j< n; j++) ne[v[i][j]][ar[i][j]]++;

        int f[4]= { 0 }, ans= 1e18;

        auto calc= [&]() {
                int an= 0;
                for (int i= 1; i<= m; i++) {
                        an+= ne[0][i]* cost[i][f[0]];
                }
                for (int i= 1; i<= m; i++) {
                        an+= ne[1][i]* cost[i][f[1]];
                }
                for (int i= 1; i<= m; i++) {
                        an+= ne[2][i]* cost[i][f[2]];
                }
                return an;
        };

        for (int i= 1; i<= m; i++) {
                for (int j= 1; j<= m; j++) {
                        if (i== j) continue;

                        for (int k= 1; k<= m; k++) {
                                if (i== k|| j== k) continue;
                                f[0]= i;
                                f[1]= j;
                                f[2]= k;
                                ans= min(ans, calc());
                        }
                }
        }
        cout << ans<< "\n";
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
