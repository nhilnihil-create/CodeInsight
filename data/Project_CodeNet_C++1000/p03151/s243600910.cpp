#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n; 
  cin >>n;
  vector<long long>a(n),b(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  vector<long long>tasu,hiku;
  for(int i=0;i<n;i++){
    long long sa;
    sa=a[i]-b[i];
    if(sa>0)tasu.push_back(sa);
    else if(sa<0)hiku.push_back(sa);
  }
  if(hiku.size()==0){
    cout<<0<<endl;
    return 0;
  }
  long long kotae=hiku.size();
  sort(tasu.rbegin(),tasu.rend());
  long long wa=0;
  for(int i=0;i<hiku.size();i++){
    wa+=hiku[i];
  }
  //cout<<wa<<endl;
  for(int i=0;i<tasu.size();i++){
    wa+=tasu[i];
    kotae++;
    if(wa>0)break;
  }
  if(wa<0)cout<<-1<<endl;
  else cout<<kotae<<endl;
  return 0;
}
    

                               