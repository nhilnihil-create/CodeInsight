#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main() {
  ll k,a,b; cin>>k>>a>>b;
  ll ans=0;
  if(a+2>=b||a>=k+1){ans=k+1;}
  else{
    ans=a;
    ans+=(b-a)*((k-a+1)/2);
    if((k-a+1)%2==1){ans++;}
  }
  cout<<ans<<endl;
} 