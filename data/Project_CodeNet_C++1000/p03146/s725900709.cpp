#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int ans=0;

void func(int s){
  if(s==4 || s==2 || s==1){
    ans+=4;
    return;
  }else if(s==0)return;
  if(s%2==0){
    ans++;
    return func(s/2);
  }else{
    ans++;
    return func(3*s+1);
  }
}

int main(){
  int s;
  cin >> s;

  func(s);
  cout << ans << endl;
}