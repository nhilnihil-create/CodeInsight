#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
#define ALL(a)  (a).begin(),(a).end()
const ll INF = 1e18+18;
const ll MAX = 200000;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
static const long double pi = 3.141592653589793;



int main(){
    ll N, M, Q;
    cin>>N>>M>>Q;
    vector<vector<ll>> X(N, vector<ll>(N, 0));
    rep(i, M){
        ll L, R;
        cin>>L>>R;
        L--; R--;
        X[L][R]++;
    }
    for(ll i=N-2; i>=0; i--){
        for(ll j=i+1;j<N; j++){
            X[i][j]+=X[i+1][j]+X[i][j-1]-X[i+1][j-1];
        }
    }
  	/*rep(i, N){
      rep(j, N){
        cout<<X[i][j]<<" ";
      }
      cout<<endl;
    }*/
    rep(i, Q){
        ll p, q;
      	cin>>p>>q;
      	p--; q--;
        cout<<X[p][q]<<endl;
    }
}