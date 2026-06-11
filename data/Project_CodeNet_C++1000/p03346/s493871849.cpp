#include<bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  int p[n],a[n]={0};
  
  for(int i=0;i<n;i++){
  	cin>>p[i];
    p[i]--;
    if(p[i]!=n-1&&a[p[i]]==0) a[p[i]]=1;
    if(p[i]!=0&&a[p[i]-1]==0) a[p[i]-1]=-1;
  }
  int count=1,ans=0;
  for(int i=0;i<n-1;i++){
  	if(a[i]==1) count++;
    if(a[i]==-1){
      ans=max(ans,count);
      count=1;
    }
  }
  ans=max(ans,count);
  cout<<n-ans<<endl;
}