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
  ll N, M;
  cin>>N>>M;
  vector<ll> A(M), B(M);
  vector<pair<ll, ll>> P(M);
  rep(i, M){
    cin>>A[i]>>B[i];
    A[i]--;B[i]--;
    P[i]=make_pair(B[i], A[i]);
  } 
  sort(ALL(P));
  ll x=-1;
  ll Cou=0;
  rep(i, M){
    if(P[i].second>x){
      Cou++;
      x=P[i].first-1;
    }
  }
  cout<<Cou<<endl;


} 