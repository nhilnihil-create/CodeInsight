#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int a[4];
  for(i=0;i<4;i++)cin>>a[i];
  for(i=0;i<4;i++){
    if(a[i]==1)cnt++;
    if(a[i]==7)cnt+=10;
    if(a[i]==9)cnt+=100;
    if(a[i]==4)cnt+=1000;
  }
  if(cnt==1111)cout<<"YES";
  else cout<<"NO";
}