#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
  ll a,b,c;
  cin>>a>>b>>c;
  ll k;
  cin>>k;
  ll t=max(a,max(b,c))*(1<<k);
  ll sum=a+b+c-max(a,max(b,c))+t;
  cout<<sum<<endl;
 return 0;
}