#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++) 
using namespace std;

int main() {
  int ans=0,m=1e9;
  vector<int> vec(5);
  rep(i,5){
    cin>>vec[i];
    int c=vec[i]%10;
    if(c!=0)m=min(m,c);
    ans+=(vec[i]+9)/10*10;
  }
  if(m!=1e9)ans=ans+m-10;
  cout<<ans<<endl;
}
    