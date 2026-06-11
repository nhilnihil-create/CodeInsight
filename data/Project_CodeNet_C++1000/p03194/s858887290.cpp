#include<bits/stdc++.h>
using namespace std;
int main(){
  map<int,int> m;
  long n,p,P,d,res=1;
  cin>>n>>P;
  p=P;
  if(n==1){cout<<p;return 0;}
  for(int i=2;i<=pow((double)P,1.0/(double)n);++i){
    d=pow(i,n);
    while(p%d==0){
      m[i]++;
      p/=d;
    }
  }
  for(auto itr=m.begin();itr!=m.end();itr++)res*=pow(itr->first,itr->second);
  cout<<res;
  return 0;
}