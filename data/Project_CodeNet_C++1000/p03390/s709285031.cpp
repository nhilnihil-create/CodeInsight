#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#define inf 999999999
#define loop(i, a, b) for (int i = (a), i##len = (b); i < i##len; ++i)
#define rep(i, n) loop(i, 0, n)
using namespace std;
typedef long long ll;
 
ll ch1(ll a,ll b){
    if(a>b)swap(a,b);
    ll s=sqrtl((long double)a*b-1);
    if(s==0)return 0;
    ll mx=(a*b-1)/s;
    ll ans=2*s;
    if(mx==s)ans--;
    if(a<=s)ans--;
    return ans;
}
 
signed main(){
  ll q,a,b;
  cin>>q;
  while(q--){
    cin>>a>>b;
    cout<<ch1(a,b)<<endl;
  }
  return 0;
}