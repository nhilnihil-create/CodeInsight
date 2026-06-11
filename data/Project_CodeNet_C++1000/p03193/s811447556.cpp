#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n,h,w;
  cin>>n>>h>>w;
  int a[n],b[n];
  for(i=0;i<n;i++)cin>>a[i]>>b[i];
  for(i=0;i<n;i++){
    if(a[i]>=h && b[i]>=w)cnt++;
  }
  cout<<cnt;
}