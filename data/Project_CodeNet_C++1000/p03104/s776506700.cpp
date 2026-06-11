#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll A, B;
  cin>>A>>B;
  ll a=0, b=0;
  ll tmpa, tmpb;
  ll ans = 0;
  for(ll i=0;i<40;++i) {
    if((A&(1ull<<i))!=0) {
      tmpa = (1ull<<i) - a;
      a += (1ull<<i);
    }
    else tmpa=0;
    if((B&(1ull<<i))!=0) {
      tmpb = b+1;
      b += (1ull<<i);
    }
    else tmpb=0;
    if(i==0) {
      if((B-A+1)%4==1 && ((A&1)!=0)) ans++; 
      if((B-A+1)%4==2) ans++;
      if((B-A+1)%4==3 && ((A&1)==0)) ans++;
    }
    if (i>0 && (tmpa+tmpb)%2==1) ans += (1ull<<i);
  }
  cout<<ans<<endl;
}
