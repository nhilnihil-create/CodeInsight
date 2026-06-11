#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll> 
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,q,x;cin>>a>>b>>q;
  ll sl,su,tl,tu,slpos,supos,tlpos,tupos;
  lvector S(a,0),T(b,0),ans(q,0);
  rep(i,a) cin>>S[i];rep(i,b) cin>>T[i];
  rep(i,q) {
    cin>>x;
    slpos=distance(S.begin(),lower_bound(ALL(S),x));
    supos=distance(S.begin(),upper_bound(ALL(S),x));
    tlpos=distance(T.begin(),lower_bound(ALL(T),x));
    tupos=distance(T.begin(),upper_bound(ALL(T),x));
    if(slpos==supos) slpos--;if(tlpos==tupos) tlpos--;
    if(x<=S[0]) sl=-1e12;else sl=S[slpos];
    if(x<=T[0]) tl=-1e12;else tl=T[tlpos];
    if(S[a-1]<=x) su=1e12;else su=S[supos];
    if(T[b-1]<=x) tu=1e12;else tu=T[tupos];
    ll ans1=abs(x-min(sl,tl));
    ll ans2=abs(x-max(su,tu));
    ll ans3=2*min(abs(x-sl),abs(x-tu))+max(abs(x-sl),abs(x-tu));
    ll ans4=2*min(abs(x-su),abs(x-tl))+max(abs(x-su),abs(x-tl));
    ans[i]=min({ans1,ans2,ans3,ans4});
  }
  rep(i,q) print(ans[i]);
  return 0;
}