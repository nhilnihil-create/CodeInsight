#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define pb(n) push_back(n)
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(20) << S << endl;
#define Vecpr vector<pair<lli,lli>>
#define mod 1000000007;
bool is_prime(lli x) {
  for(lli i = 2; i * i <= x; i++) {
    if(x % i == 0) return false;
  }
  return true;
}
int main() {
  lli A,B,C=1,D=0,E=0,F=0,G=0,H=0,N,M;
  string S;
  cin >> A >> B >> C;
  rep(i,0,C){
    if(i%2==0){
      if(A%2==1)A--;
      B+=A/2;
      A-=A/2;
    }
    else{
      if(B%2==1)B--;
      A+=B/2;
      B-=B/2;
    }
  }
  cout << A << " " << B << endl;
}