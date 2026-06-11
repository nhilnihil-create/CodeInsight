#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll k,a,b;
  cin>>k>>a>>b;
  if(a>=b-1){
    cout<<1+k<<endl;
    return 0;
  }
  if(k-(a-1)<=0){
    cout<<1+k<<endl;
    return 0;
  }
  k-=a-1;
  ll now=a;
  if(k%2==1){
    now++;
    k--;
  }
  cout<<now+k/2*(b-a)<<endl;
}