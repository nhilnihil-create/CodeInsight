#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,c=-1,j;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a[i];
  sort(a.begin(),a.end(),greater<int>());
  for(int i=1;i<n;i++){
    if(c<min(a[0]-a[i],a[i])){
      c=min(a[0]-a[i],a[i]);
      j=i;
    }
  }
  cout<<a[0]<<" "<<a[j]<<endl;
}