#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll gcd(ll x,ll y){
  return y==0?x:gcd(y,x%y);
}

int main(){
  int t;
  cin>>t;

  for(int i=0;i<t;i++){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a<b||d<b) cout<<"No"<<endl;
    else{
      ll x=(a-c-1)/b+1;
      if(a-b*x<0) cout<<"No"<<endl;
      else if(b==d) cout<<"Yes"<<endl;
      else{
        ll y=gcd(b,d);
        ll z=y-(c-(a-b*x))%y;
        ll next=z+c;
        if(next-b<0) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
      }
    }


  }

  return 0;
}
