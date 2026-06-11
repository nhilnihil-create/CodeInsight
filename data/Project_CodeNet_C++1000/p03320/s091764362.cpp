#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll sunuke(ll m){
  ll ret=m;
  ll dig=0;
  ll digsum=0;
  ll temp=m;
  while(temp>0){
    dig++;
    digsum+=temp%10;
    temp/=10;
  }
  double sun=double(m)/(double)digsum;
  for(int i=0;i<dig;i++){
    ll power=pow(10,i+1);
    ll x=m-(m%power)+power-1;
    ll digsumx=0;
    ll tempx=x;
    while(tempx>0){
      digsumx+=tempx%10;
      tempx/=10;
    }
    double sunx=(double)x/(double)digsumx;
    if(sun>sunx){
      sun=sunx;
      ret=x;
    }
  }
  return ret;
}

int main(){
  ll n;
  cin >> n;
  ll t=0;
  rep(i,n){
    ll y=sunuke(t+1);
    cout << y << endl;
    t=y;
  }
return 0;}