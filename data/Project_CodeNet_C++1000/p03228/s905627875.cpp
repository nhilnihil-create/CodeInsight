#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int INF=1e9;
const int MOD=1e9+7;
const double pi=acos(-1);

int main(){
  ll a,b,k;
  cin >> a >> b >> k;
  rep(i,k){
    if(i%2==0){
      if(a%2==1)a--;
    
      b+=a/2;
      a/=2;
    }
    if(i%2==1){
      if(b%2==1)b--;
    
      a+=b/2;
      b/=2;
    }
  }
  cout << a << " "  << b << endl;
}
