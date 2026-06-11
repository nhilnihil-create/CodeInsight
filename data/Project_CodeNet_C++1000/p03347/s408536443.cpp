#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  long long a[n];
  for(int i=0;i<n;i++){
    long long k;
    cin>>k;
    a[i]=k;
  }
  bool t=true;
  long long ans=0;
  for(int i=0;i<n;i++){
    if(i==0){
      if(a[0]!=0)t=false;
    }
    else{
      if(a[i]==a[i-1]+1)ans++;
      else if(a[i]<=a[i-1])ans+=a[i];
      else t=false;
    }
    if(!t)break;
  }
  if(!t)cout<<-1<<endl;
  else cout<<ans<<endl;
}
