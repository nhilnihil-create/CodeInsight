#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n,m;
  cin>>n>>m;
  if(n>=m){
    cout<<"0";
    return 0;
  }
  vector<long long> x(m),a(m-1);
  for(long long i=0;i<m;i++){
  	cin>>x[i];
  }
  sort(x.begin(),x.end());
 
  for(long long i=m-2;i>=0;i--){
  	a[i]=x[i+1]-x[i];
  }
  
  sort(a.begin(),a.end());
  
  int64_t ans=x[m-1]-x[0];
  
  for(long long i=0;i<n-1;i++){
  	ans-=a[m-2-i];
  }
  cout<<ans;
}