#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    int n, m, q;    cin >> n >> m >> q;
    vector<vector<ll>> sum(n+1, vector<ll>(n+1, 0));
    REP(i, m){
        int a, b;   cin >> a >> b;
        sum[a][b] += 1;
    }
    REP(i, n+1){
        REP(j, n) sum[i][j+1] += sum[i][j];
    }
    while(0<q--){
        int a, b;   cin >> a >> b;
        ll res=0;
        FOR(i, a, b+1) res += sum[i][b]-sum[i][i-1];
        cout << res << endl;
    }
    // REP(i, n+1){
    //     REP(j, n+1) cout << sum[i][j] << ' ';
    //     cout << endl;
    // }
}