#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  string ans;
  if((a*b)%2==0){
    ans = "Even";
  }
  else{
    ans = "Odd";
  }
  cout<<ans<<endl;
}