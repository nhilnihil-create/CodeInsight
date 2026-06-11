#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

const int MOD=1000000007;
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;

int main() {
  ll a , b , k; cin >> a >> b >> k ;
  
  rep(i,k){
    if(i%2==0){
      if(a%2==1) a--;
      b+=a/2;
      a/=2;
    }
    else{
      if(b%2==1) b--;
      a+=b/2;
      b/=2;
    }
  }
  cout<<a<<" "<<b<<endl;
}

