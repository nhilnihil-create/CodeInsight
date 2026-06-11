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

ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return a * b / gcd (a, b);
}

int main(){
  ll N;
  cin>>N;
  vector<ll> A(N);
  ll Ans=-1;
  rep(i, N){
    cin>>A[i];
    if(i==0){
      Ans=A[0];
      continue;
    }
    Ans=gcd(Ans, A[i]);
  }
  cout<<Ans<<endl;


}