#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)cin>>a[i];
  for(i=1;i<n;i++){
    if(a[i]==a[i-1]){
      cnt++;
      i++;
    }
  }
  cout<<cnt;
}