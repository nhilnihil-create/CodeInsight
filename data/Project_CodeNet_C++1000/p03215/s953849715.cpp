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
    ll n,k; cin >> n >> k;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl sum(n+1,0);
    rep(i,n) sum[i+1] = sum[i] + a[i];
    vl v;
    rep(i,n){
        REP(j,i+1,n+1){
            v.push_back(sum[j]-sum[i]);
        }
    }
    ll ans = 0;
    ll m = v.size();
    vl vv = v;
    for(ll bit=40; bit>=0; bit--){
        ll cnt = 0;
        for(auto i : v){
            if(i & (1LL<<bit)){
                cnt++;
                vv.push_back(i);
            }
        }
        if(cnt >= k){
            ans += (1LL<<bit);
            v = vv;
        }
        vv.clear();
    }
    cout << ans << endl;
}
