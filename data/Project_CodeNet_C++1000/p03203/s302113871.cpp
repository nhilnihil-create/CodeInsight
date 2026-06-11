#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

int main(){
    ll h,w,n; cin >> h >> w >> n;
    vvl obs(w);
    rep(i,n){
        ll x,y; cin >> x >> y;
        x--; y--;
        obs[y].push_back(x);
    }
    rep(i,w) sort(all(obs[i]));
    ll ans = h;
    ll cnt = 0;
    rep(i,h){
        if(i>=w) break;
        while(binary_search(all(obs[i]),i+cnt)) cnt++;
        auto itr = upper_bound(all(obs[i]),i+cnt);
        if(itr != obs[i].end()) ans = min(ans, *itr);
    }
    cout << ans << endl;
}
