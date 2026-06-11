#include <iostream>
#include <algorithm>
using namespace std; typedef long long ll; const int INF=1e9;
typedef pair<int,int> P;
ll s(ll a) {ll res=0; while(a>0) res+=a%10, a/=10; return res;}
bool val_ok(ll a,ll b) {return a*s(b)<=b*s(a);}
bool check(ll a) {
  ll ke=0, a2=a;
  while(a2>0) ke++, a2/=10LL; a2=a;
  bool able=true;
  for(ll i=0,j=1;i<ke;i++,j*=10LL) {
    while(a2%(j*10LL)/j != 9LL) {
      a2+=j;
      if (val_ok(a,a2)) continue;
      else {able=false; break;}
    }
    if (!able) break;
  }
  if (able) return true;
  else return false;
}
int main() {
  ll k; cin>>k;
  ll j=1,j2=10000;
  for(ll i=1, all=0; all<k;i+=j) {
    if ((i+1)%j2 == 0) j*=10,j2*=10;
    if (check(i)) {cout<<i<<endl; all++;}
    //cout<<i<<endl; all++;
    if (i>1e15) break;
  }
}