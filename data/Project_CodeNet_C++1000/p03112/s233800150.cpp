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
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll A, B, Q;
  cin>>A>>B>>Q;
  vector<ll> S(A+1), T(B+1);
  for(ll i=0;i<A;++i) cin>>S[i];
  for(ll i=0;i<B;++i) cin>>T[i];
  S[A] = big;
  T[B] = big;
  ll ans[Q];
  ll x;
  ll indexs, indext, index;
  ll s1, s2, t1, t2;
  ll tmpans;
  for(ll i=0;i<Q;++i) {
    cin>>x;
    indexs = lower_bound(S.begin(), S.end(), x) - S.begin();
    indext = lower_bound(T.begin(), T.end(), x) - T.begin();
    if(indexs<A) {
      s2 = S[indexs];
    }
    else s2 = big;
    if(indext<B) {
      t2 = T[indext];
    }
    else t2 = big;
    if(indexs>0) s1 = S[indexs-1];
    else s1 = -big;
    if(indext>0) t1 = T[indext-1];
    else t1 = -big;
    ans[i] = big;
    tmpans = 0;
    tmpans += abs(x-s1);
    index = lower_bound(T.begin(), T.end(), s1)- T.begin();
    if(0<index && index<B) {
      tmpans += min(abs(s1-T[index]), abs(s1-T[index-1]));
    }
    else if(index==0) {
      tmpans += abs(s1-T[index]);
    }
    else tmpans += abs(s1-T[index-1]);
    ans[i] = min(ans[i], tmpans);
    tmpans = 0;
    tmpans += abs(x-s2);
    index = lower_bound(T.begin(), T.end(), s2)- T.begin();
    if(0<index && index<B) {
      tmpans += min(abs(s2-T[index]), abs(s2-T[index-1]));
    }
    else if(index==0) {
      tmpans += abs(s2-T[index]);
    }
    else tmpans += abs(s2-T[index-1]);
    ans[i] = min(ans[i], tmpans);

    tmpans = 0;
    tmpans += abs(x-t1);
    index = lower_bound(S.begin(), S.end(), t1)- S.begin();
    if(0<index && index<A) {
      tmpans += min(abs(t1-S[index]), abs(t1-S[index-1]));
    }
    else if(index==0) {
      tmpans += abs(t1-S[index]);
    }
    else tmpans += abs(t1-S[index-1]);
    ans[i] = min(ans[i], tmpans);
    tmpans = 0;
    tmpans += abs(x-t2);
    index = lower_bound(S.begin(), S.end(), t2)- S.begin();
    if(0<index && index<A) {
      tmpans += min(abs(t2-S[index]), abs(t2-S[index-1]));
    }
    else if(index==0) {
      tmpans += abs(t2-S[index]);
    }
    else tmpans += abs(t2-S[index-1]);
    ans[i] = min(ans[i], tmpans);
  }
  for(ll i=0;i<Q;++i) cout<<ans[i]<<endl;
}

