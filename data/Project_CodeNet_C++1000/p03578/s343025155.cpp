#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll> 
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  lvector D(n,0);rep(i,n) cin>>D[i];
  ll m;cin>>m;
  lvector T(m,0);rep(i,m) cin>>T[i];
  sort(ALL(D));sort(ALL(T));
  ll dpos=0,tpos=0,val=0;
  bool isok=false;
  while(dpos<n) {
    if(D[dpos]==T[tpos]) {
      val++;dpos++;tpos++;
    }
    else dpos++;
    if(val==m) {
      isok=true;break;
    }
  }
  puts(isok?"YES":"NO");
  return 0;
}