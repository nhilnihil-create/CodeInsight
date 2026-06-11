#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
#define PI 3.14159265359
#define MOD 998244353
const int MAX = 510000;

int main() {
  ll N,M;cin>>N>>M;
  ll ans=0;
  if(N==1&&M==1){ans=1;}
  if(N==1&&M!=1){ans=M-2;}
  if(N!=1&&M==1){ans=N-2;}
  if(N>1&&M>1){ans=(N-2ll)*(M-2ll);}
  cout<<ans;
}