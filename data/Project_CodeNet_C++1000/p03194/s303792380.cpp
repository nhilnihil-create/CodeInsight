#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
  ll n,k;
  cin>>n>>k;
  if(n==1){
    cout<<k;
    return 0;
  }
  if(n>1000000){
    cout<<1;
    return 0;
  }
   double c=1;
  for(double i=1;;i++){
    if(k%(ll)pow(i,(double)n)==0){
      c=i;
    }
    if(k<(ll)pow(i,(double)n)) break;
  }
  cout<<(ll)c;
}