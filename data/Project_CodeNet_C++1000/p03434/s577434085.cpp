#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,a[110],alice=0,bob=0;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n,greater<int>());
  for(int i=0;i<n;i++){
    if(i%2==0) alice+=a[i];
    else bob+=a[i];
  }
  cout<<alice-bob;
}
