#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<iomanip>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

const int MAX = 510000;
const int MOD = 1000000007;
const int MAX_V = 200;

int d[MAX_V][MAX_V];
int V;

void warshall_floyd() {
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main(){
  ll H ,W; cin >> H >> W;
  V = 10;
  rep(i,V){
    rep(j,V){
      ll a; cin >> a;
      d[i][j] = a;
    }
  }
  warshall_floyd();
  ll ans = 0;
  rep(i,H){
    rep(j,W){
      ll b; cin >> b;
      if(b == -1) continue;
      else{
        ans += d[b][1];
      }
    }
  }
  cout << ans << endl;
}
