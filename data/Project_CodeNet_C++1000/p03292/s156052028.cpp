#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans;
  if(a>=b&&a>=c){
    ans=min(abs(b-a)+abs(b-c),abs(c-a)+abs(b-c));
  }
  else if(b>=a&&b>=c){
    ans=min(abs(a-b)+abs(a-c),abs(c-b)+abs(a-c));
  }
  else{
    ans=min(abs(a-c)+abs(a-b),abs(b-c)+abs(a-b));
  }
  cout<<ans<<endl;
}
