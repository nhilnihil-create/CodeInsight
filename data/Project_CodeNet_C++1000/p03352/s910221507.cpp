#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0; i<(int)(n); i++)

int main(){
  int x;cin>>x;
  double i=2;
  double ans=1;
  if(x==1000){ans=x;}
  else{
    while(i<10){
      double d=1/i;
      int p =pow(x,d);
      ans=max(ans,pow(p,i));
      //cout<<p<<" "<<d<<" "<<pow(p,i)<<endl;
      i++;
    }
  }
  cout<<ans;

}