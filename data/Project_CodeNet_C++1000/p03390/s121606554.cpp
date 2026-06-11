#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a) for(int i=0;i<(a);i++)
const ll MOD=1000000007;

int solve(ll X,ll A,ll B){
  ll INC,DEC;
  if(X%2==1){
    INC=max(1LL,(X+1)/2-2),DEC=min(X,(X+1)/2+2);
  }else{
    INC=max(1LL,X/2-3),DEC=min(X,X/2+1+3);
  }
  if(A<INC) INC++;
  if(B>DEC) DEC--;
  rep(i,10){
    if(INC==A) INC++;
    if(DEC==B) DEC--;
    if(INC*DEC>=A*B) return 0;
    INC++,DEC--;
  }
  return 1;
}

int main(){
  int Q; cin>>Q;
  rep(i,Q){
    ll A,B; cin>>A>>B;
    if(A>B) swap(A,B);
    ll ok=2*A-2,ng=2*B;
    while(abs(ok-ng)>1){
      ll mid=(ok+ng)/2;
      if(solve(mid,A,B)) ok=mid;
      else ng=mid;
    }
    cout<<(ok-1)<<endl;
  }
  return 0;
}
