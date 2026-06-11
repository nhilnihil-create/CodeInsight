#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  string ans;
  if(n==0){
    cout<<0<<endl;
  }
  while(n!=0){
    if(n%2!=0){
      n--;
      ans='1'+ans;
    }else{
      ans='0'+ans;
    }
    n/=-2;
  }
  cout<<ans<<endl;
} 