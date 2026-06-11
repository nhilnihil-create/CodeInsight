#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int n,m;
  cin>>n;
  long long d[n];
  for(int i=0;i<n;i++) cin>>d[i];
  cin>>m;
  long long t[m];
  for(int i=0;i<m;i++) cin>>t[i];
  sort(d,d+n);
  sort(t,t+m);
  int i=0,j=0;
  while(j<m){
    if(d[i]==t[j]){
      j++;
      i++;
    }
    else if(d[i]<t[j]){
      i++;
    }
    else break;
  }
  
  if(j==m) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  
}