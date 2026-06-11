#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main(){
  ll a,b;
  cin>>a>>b;
  
  ll ans;
  if(a==b){
    ans=a;
  }
  else if(a%2==1 && b%2==0){
    ans=a^b^((b-a-1)/2%2);
  }
  else if(a%2==1 && b%2==1){
    b++;
    ans=a^b^((b-a-1)/2%2);
    ans^=b;
  }
  else if(a%2==0 && b%2==0){
    a++;
    ans=a^b^((b-a-1)/2%2);
    ans^=a-1;
  }
  else if(a%2==0 && b%2==1){
    a++;
    b++;
    ans=a^b^((b-a-1)/2%2);
    ans=ans^(a-1)^b;
  }
 
  cout<<ans<<endl;
  return 0;
}