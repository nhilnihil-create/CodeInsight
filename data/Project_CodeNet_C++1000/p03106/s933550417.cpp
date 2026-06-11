#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,k;
  cin>>a>>b>>k;
  
  int cnt=0,ans;
  for(int i=100;i>0;i--){
    if(a%i==0 && b%i==0){
      cnt++;
    }
    if(cnt==k){
      ans=i;
      break;
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}