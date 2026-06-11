#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
LL a,b;
LL get(LL x,int y){
  if(x<0)return 0;
  LL z=(x+1)/(1ll<<y+1);
  LL t=(x+1)%(1ll<<y+1);
  z*=1ll<<y;
  if(t>(1ll<<y)){
    t-=1ll<<y;
    z+=t;
  }
 // cout<<z<<endl;
  return z&1;
}
int ch(int x){
  //0  2^x
  //1  2^x
  return (get(a-1,x)-get(b,x)+2)%2;
}
int main() {
  ios::sync_with_stdio(false);
  cin>>a>>b;//1 2 3 4
  //00 01 10 11 00 01 10
  LL ans=0;
  for(int i=0;i<50;i++){
    if(ch(i))ans^=1ll<<i;
  }
  cout<<ans<<'\n';
  return 0;
}