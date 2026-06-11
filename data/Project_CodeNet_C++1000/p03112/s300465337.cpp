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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int A, B, Q;
  cin>>A>>B>>Q;
  vector<ll> S(A), T(B);
  for(int i=0;i<A;++i) cin>>S[i];
  for(int i=0;i<B;++i) cin>>T[i];
  ll X;
  ll hidaris, migis, hidarit, migit;
  ll hs, ms, ht, mt;
  ll ans;
  for(int i=0;i<Q;++i) {
    cin>>X;
    hidaris = upper_bound(S.begin(), S.end(), X) - S.begin() - 1;
    migis = lower_bound(S.begin(), S.end(), X) - S.begin();
    hidarit = upper_bound(T.begin(), T.end(), X) - T.begin() - 1;
    migit = lower_bound(T.begin(), T.end(), X) - T.begin();
    if(hidaris<0) hs = big;
    else hs = S[hidaris];
    if(migis>=A) ms = big;
    else ms = S[migis];
    if(hidarit<0) ht = big;
    else ht = T[hidarit];
    if(migit>=B) mt = big;
    else mt = T[migit];
    ans = abs(X-hs) + min(abs(hs-ht), abs(hs-mt));
    ans = min(ans, abs(X-ms) + min(abs(ms-ht), abs(ms-mt)));
    ans = min(ans, abs(X-ht) + min(abs(ht-hs), abs(ht-ms)));
    ans = min(ans, abs(X-mt) + min(abs(mt-hs), abs(mt-ms)));
    cout<<ans<<endl;
  }
}

