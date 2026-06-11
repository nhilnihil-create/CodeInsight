#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)cin>>a[i];
  int mi=INT_MAX;
  int sum=0;
  for(i=0;i<n;i++)sum+=a[i];
  for(i=0;i<n;i++){
    if(mi>max(sum-n*a[i],n*a[i]-sum)){
      mi=max(sum-n*a[i],n*a[i]-sum);
      cnt=i;
    }
  }
  cout<<cnt;
}