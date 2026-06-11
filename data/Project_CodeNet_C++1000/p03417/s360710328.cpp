#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

#define repr(i, n) for(int i = n; i >= 0; i--)
#define reprl(i, n) for(ll i = n; i >= 0; i--)
#define all(v) v.begin(), v.end()
ll gcd(ll a,ll b) {
  return b? gcd(b,a%b): a;  
}
ll lcm(ll a,ll b) {
  return a*b/gcd(a,b);
}
bool isLowerCase(char c){
  return (c>='a'&&c<='z');
}
const string outputYesNo(bool ans){
  return (ans?"Yes":"No");
}
int main() {
  ll n,m;cin>>n>>m;
  ll ans=0;
  if(n==1){
    if(m==1){
      ans=1;
    }else if(m==2){
      ans=0;
    }else if(m>=3){
      ans=m-2;
    }
  }else if(n==2){
    if(m==1){
      ans=0;
    }else if(m==2){
      ans=0;
    }else if(m>=3){
      ans=0;
    }
  }else if(n>=3){
    if(m==1){
      ans=n-2;
    }else if(m==2){
      ans=0;
    }else if(m>=3){
      ans=(n-2)*(m-2);
    }
  }
  cout<<ans<<endl;
  return 0;
}
