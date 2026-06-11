#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int a,b;
  cin>>a>>b;
  int cnt=0;
  
  for(int i=a;i<=b;i++){
    string s=to_string(i);
    string Rs=s;
    reverse(Rs.begin(),Rs.end());
    if(s==Rs)cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}