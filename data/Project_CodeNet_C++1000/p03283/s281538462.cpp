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

ll dpans[510][510];
ll dptmp[510][510];

int main(){
  ll N, M, Q; cin >> N >> M >> Q;
  vector<P> a(M); rep(i,M) cin >> a[i].fi >> a[i].sc; rep(i,M){a[i].fi--; a[i].sc--;}
  vector<P> b(Q); rep(i,Q) cin >> b[i].fi >> b[i].sc; rep(i,Q){b[i].fi--; b[i].sc--;}

  SORT(a);
  // table作成してしまう O(N^2)
  rep(i,M) dptmp[a[i].fi][a[i].sc]++;

  for(ll i = N - 1; i >= 0; i--){
    // i is left side
    for(ll j = 0; j < N ; j++){
      // j is right side
      if(dptmp[i][j]){
        for(ll k = j; k < N; k++){
          dpans[i][k] += dptmp[i][j];
        }
      }
    }
  }
  // rep(i,N) rep(j,N) cout << i << " " << j << " " << dpans[i][j] << endl;
  // したから上に足していく
  rep(j,N){
    for(ll i = N - 1; i > 0; i--){
      dpans[i - 1][j] += dpans[i][j];
    }
  }

  // rep(i,N) rep(j,N) cout << i << " " << j << " " << dpans[i][j] << endl;

  rep(i,Q){
    cout << dpans[b[i].fi][b[i].sc] << endl;
  }
}
