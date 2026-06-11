#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n,k;
  cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int count=k;
  int ans=1;
  while(count<n){
    count+=(k-1);
    ++ans;
  }
  cout<<ans<<endl;
  return 0;
}