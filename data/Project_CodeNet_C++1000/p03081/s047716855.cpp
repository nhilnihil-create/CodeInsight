#include <iostream>
#include <cstdlib>
#include <cmath>
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

int main() {
    ll n,q; cin >> n >> q;
    string s; cin >> s;
    vector<char> c(q);
    vl move(q);
    rep(i,q){
        char a,b; cin >> a >> b;
        c[i] = a;
        move[i] = b=='L' ? -1 : 1;
    }
    ll ok = -1;
    ll ng = n;
    while(ng-ok>1){
        ll mid = (ok + ng) / 2;
        ll cur = mid;
        rep(i,q){
            if(s[cur]==c[i]){
                if(move[i]==1) cur++;
                else cur--;
            }
            if(cur == n || cur == -1) break;
        }
        if(cur==-1){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    ll ans = ok + 1;
    ok = n;
    ng = -1;
    while(ok-ng>1){
        ll mid = (ok + ng) / 2;
        ll cur = mid;
        rep(i,q){
            if(s[cur]==c[i]){
                if(move[i]==1) cur++;
                else cur--;
            }
            if(cur == n || cur == -1) break;
        }
        if(cur==n){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    ans += n-ok;
    cout << n-ans << endl;
}
