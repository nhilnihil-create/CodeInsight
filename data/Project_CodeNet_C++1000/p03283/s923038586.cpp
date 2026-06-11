#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i = 0; i <x; i++)
#define forep(i,k,x) for(ll i = k; i < x; i++)
typedef long long ll;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;


int main(){
  int N, M , Q;
  cin >> N >> M >> Q;
  vector<vector<ll>> sum(N+2,vector<ll>(N+2,0));

  rep(i,M){
    int l,r;
    cin >> l >> r;
    sum[l][r]++;
  }

  rep(i,N) rep(j,N) sum[i+1][j+1] += sum[i+1][j] + sum[i][j+1] - sum[i][j];

  rep(i,Q){
    int p,q;
    cin >> p >> q;
    ll ans = sum[q][q] - sum[p-1][q] - sum[q][p-1] + sum[p-1][p-1];
    cout << ans << endl;
  }


}
