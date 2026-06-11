#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll a,b,k;cin>>a>>b>>k;

  rep(i, k){
    if(i%2==0){
      if(a%2)a--;
      b+=(a/=2);
    }else{
      if(b%2)b--;
      a+=(b/=2);
    }
//  cout<<a<<' '<<b<<endl;

  }

  cout<<a<<' '<<b;

  return 0;
}