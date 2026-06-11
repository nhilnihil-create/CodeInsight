#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,b=1000000010;
  cin>>n;
  vector<long long> x(n+1),a(n);
  for(int i=0;i<=n;i++)cin>>x[i];
  sort(x.begin(),x.end());
  for(int i=0;i<n;++i){
    a[i]=x[i+1]-x[i];
    b=min(a[i],b);
  }

  for(long long i=b;i>0;--i){
    bool f=true;
    for(int j=0;j<n;++j){
      if(a[j]%i!=0){f=false;break;}
    }
    if(f)return cout<<i,0;
  }
}