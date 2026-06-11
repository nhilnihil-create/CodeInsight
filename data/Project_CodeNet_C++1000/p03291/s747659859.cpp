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
  string S;
  cin>>S;
  ll Size=S.size();
  ll Ans=0;
  ll A=0;
  ll B=0;
  ll Cou=0;
  ll Tri=1;
  rep(i, Size){
    if(S.at(i)=='A'){
      A+=Tri;
    }
    if(S.at(i)=='B'){
      B+=A;
    }
    if(S.at(i)=='C'){
      Ans+=B;
    }
    if(S.at(i)=='?'){
      ll AA=A*3+Tri;
      ll BB=A+B*3;
      Ans=Ans*3+B;
      A=AA;
      B=BB;
      Cou++;
      Tri*=3;
    }
    A%=MOD;
    B%=MOD;
    Ans%=MOD;
    Tri%=MOD;
	//cout<<A<<" "<<B<<" "<<Ans<<endl;

  }
  cout<<Ans<<endl;
} 