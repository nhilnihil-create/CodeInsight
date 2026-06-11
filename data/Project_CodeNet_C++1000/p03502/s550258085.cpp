#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)
 
int main(){
  ll n;
  cin>>n;
  ll before=n;
  ll total=0;
  while(n>0){
    total+=(n%10);
    n/=10;
  }
  if(before%total==0)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}