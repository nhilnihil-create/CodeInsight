#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  ll n;
  cin>>n;
  ll p,q,r;
  for(ll a=1; a<=3500; a++){
    for(ll b=1; b<=3500; b++){
      if(4*a*b-n*b-n*a==0) continue;
      if(n*a*b % (4*a*b-n*b-n*a) == 0 && 1<=n*a*b/(4*a*b-n*b-n*a) && n*a*b/(4*a*b-n*b-n*a)<=3500){
        p=a; q=b; r=n*a*b/(4*a*b-n*b-n*a);
        break;
      }
    }
  }
  cout<<p<<" "<<q<<" "<<r<<endl;
}
