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
  cin >> N >> A >> B;
  vector<int>P(3,0);
  rep(i,0,N){
    cin >> C;
    if(C<A+1)P[0]++;
    else if(C>A&&C<B+1)P[1]++;
    else P[2]++;
  }
  Sort(P);
  Out(P[0]);
}