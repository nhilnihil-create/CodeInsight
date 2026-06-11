#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  ll d,g;
  cin>>d>>g;
  ll p[d],c[d];
  for(int i=0;i<d;i++){
    cin>>p[i]>>c[i];
  }
  ll ans=1001001001;
  for(int i=0;i<(1<<d);i++){
    bitset<10> bit(i);
    ll x=0,y=-1,z=0;
    for(int j=0;j<d;j++){
      if(bit.test(j)){
        x+=(j+1)*100*p[j]+c[j];
        z+=p[j];
      }else{
        y=j;
      }
    }
    if(x<g && g-x<100*(y+1)*p[y]){
      z+=((g-x)/100-1)/(y+1)+1;
      ans=min(ans,z);
    }else if(x>=g){
      ans=min(ans,z);
    }
  }
  cout<<ans<<endl;
  return 0;
}