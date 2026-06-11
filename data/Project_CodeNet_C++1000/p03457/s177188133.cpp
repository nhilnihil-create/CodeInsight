#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;cin>>n;
  vector<long long> t(n),x(n),y(n);
  for(int i=0;i<n;++i)cin>>t[i]>>x[i]>>y[i];
  for(int i=0;i<n;++i){
    long long k,s;
    if(i==0)k=t[i],s=x[i]+y[i];
    else k=abs(t[i]-k),s=abs(s-(x[i]+y[i]));
    int a=k%2,b=s%2;
    if(s>k||a!=b)return cout<<"No",0;
  }
  cout<<"Yes",0;
}