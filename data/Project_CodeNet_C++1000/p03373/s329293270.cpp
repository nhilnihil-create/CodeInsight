#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

int main() {
  ll a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  ll res=-1;
  for(int i=0;i<=x;i++){
    ll temp;
    if((x-i)<=y){
      temp=a*i+c*2*(x-i)+b*(y-x+i);
    }
    else temp=a*i+c*2*(x-i);
    if(res<0 || res>temp) res=temp;
  }
  for(int i=0;i<=y;i++){
    ll temp;
    if((y-i)<=x){
      temp=a*(x-y+i)+c*2*(y-i)+b*y;
    }
    else temp=b*i+c*2*(y-i);
    if(res>temp) res=temp;
  }  
  cout<<res<<endl;
  return 0;
}