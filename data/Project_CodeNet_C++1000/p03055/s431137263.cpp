#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <cmath>
using namespace std;
#define MOD 1000000007
#define INF 1<<30
#define LINF 1LL<<62
#define MAX 510000
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> P;
typedef vector<pair<ll, ll>> vpl;
const int mod = 1e9 + 7;

int main(){
    ll n; cin >> n;
    vvl G(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<ll> q;
    q.push(0);
    vl d(n,INF);
    d[0] = 0;
    ll mx = 0;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(auto v : G[u]){
            if(d[v] != INF) continue;
            d[v] = d[u] + 1;
            q.push(v);
            mx = max(d[v],mx);
        }
    }
    ll start;
    rep(i,n) if(d[i]==mx) start = i;
    q.push(start);
    mx = 0;
    rep(i,n) d[i] = INF;
    d[start] = 0;
    while(!q.empty()){
        ll u = q.front(); q.pop();
        for(auto v : G[u]){
            if(d[v] != INF) continue;
            d[v] = d[u] + 1;
            q.push(v);
            mx = max(d[v],mx);
        }
    }
    if(mx%3==1) puts("Second");
    else puts("First");
    //cout << mx << endl;
}