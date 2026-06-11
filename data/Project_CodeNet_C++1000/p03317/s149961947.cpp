#include <bits/stdc++.h>
using namespace std;
int main(){
  int c=0,n,k;cin>>n>>k;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a.begin(),a.end());
  for(int i=0;i<n;++i){
    if(a[0]==a[n-1])break;
    if(a[i]==a[i+1])continue;
    for(int j=1;j<k;++j){
      if(i+j>=n)break;
      a[i+j]=a[i];
    }
    c++;
  }
  cout<<c;
}