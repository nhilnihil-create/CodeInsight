#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; cin >>n;
  vector<long long>a(n),b(n),c(n,0),d(n,0);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++){
    if(a[i]-b[i]<0)c[i]=a[i]-b[i];
    else if(a[i]-b[i]>0)d[i]=a[i]-b[i];
  }
  sort(c.begin(),c.end());
  sort(d.rbegin(),d.rend());
  long long count=0;
  long long sum=0;
  for(int i=0;i<n;i++){
    if(c[i]==0)break;
    sum+=c[i];
    count++;
  }
  for(int i=0;i<n;i++){
    if(d[i]==0||sum>=0)break;
    sum+=d[i];
    count++;
    if(sum>=0)break;
  }
  if(sum<0){
    cout<<-1<<endl;
  }else{
    cout<<count<<endl;
  }
  return 0;
}
                               