#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int a,b; cin>>a>>b;
  int ans=max(2*a-1,2*b-1);
  ans=max(ans,a+b);
  cout<<ans;
}