#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
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
vector<ll> res;
int v[3] = {3, 5, 7};
ll n;

void dfs(ll value, ll mask=0){
    REP(i, 3){
        ll nv = value*10+v[i];
        ll nm = mask | (1<<i);
        if((nm==7) && nv<=n) res.push_back(nv);
        if(nv<=n) dfs(nv, nm);
    }
}



int main(){
    cin >> n;
    dfs(0);
    cout << res.size() << endl;
}