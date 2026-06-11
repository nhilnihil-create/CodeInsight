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



int main(){
  ll D, G;
  cin>>D>>G;
  vector<ll> P(D), C(D);
  rep(i, D){
    cin>>P[i]>>C[i];
  }
  ll Ans=INF;
  for(ll i=0; i<(1<<D); i++){
    ll Point=0;
    ll Cou=0;
    rep(j, D){
      if(i&(1<<j)){
        Point+=C[j];
        Point+=(100*(j+1))*P[j];
        Cou+=P[j];
      }
    }
    //cout<<Point;
    if(Point>=G){
      Ans=min(Ans,Cou);
      continue;
    }
    //cout<<'&';
    for(ll j=D-1; j>=0; j--){
      if(i&(1<<j))continue;
      ll K=(G-Point)/((j+1)*100);
      if((G-Point)%((j+1)*100)>0)K++;
      if(K<=P[j]-1){
        Cou+=K;
        break;
      }else{
        Cou=INF;
        break;
      }
    }
	Ans=min(Ans, Cou);

  }
  cout<<Ans<<endl;
} 