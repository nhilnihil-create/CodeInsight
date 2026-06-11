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
    int h, w;   cin >> h >> w;
    vector<vector<ll>> spell(10, vector<ll>(10)), wall(h, vector<ll>(w));
    
    REP(i, 10) REP(j, 10) cin >> spell[i][j];
    REP(i, h) REP(j, w) cin >> wall[i][j];
    
    
    REP(k ,10){
        REP(i, 10){
            REP(j, 10){
                spell[i][j] = min(spell[i][j], spell[i][k]+spell[k][j]);
            }
        }
    }
    ll res=0;
    REP(i, h){
        REP(j, w){
            int x = wall[i][j];
            if(x<0) continue;
            res += spell[x][1];
        }
    }
    cout << res << endl;
}