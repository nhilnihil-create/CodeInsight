#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
vector<ll> fac, finv, inv;


int main(){
    int h, w;  cin >> h >> w;
    vector<vector<int>> g(h, vector<int>(w));
    
    REP(i, h) REP(j, w) cin >> g[i][j];
    vector<pair<ll, ll>> bef, aft;

    
    REP(i, h){
        REP(j, w-1){
            if(g[i][j]&1){
                g[i][j] -= 1;
                g[i][j+1] += 1;
                bef.push_back({i, j});
                aft.push_back({i, j+1});
            }
        }
    }

    REP(i, h-1){
        if(g[i].back()&1){
            g[i].back() -= 1;
            g[i+1].back() += 1;
            bef.push_back({i, w-1});
            aft.push_back({i+1, w-1});
        }
    }

    cout << aft.size() << endl;
    REP(i, aft.size())
        cout << bef[i].first+1  << ' ' << bef[i].second+1 << ' ' <<
        aft[i].first+1  << ' ' << aft[i].second+1 <<  endl;

    

}