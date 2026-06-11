#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;
  cin>>n>>k;
  ll c=n/k;
  ll d=c*c*c;
  if(k%2==0){
     if(k*c+k/2<=n)
       c++;
     d+=c*c*c; 
  }
  cout<<d;
  return 0;
}