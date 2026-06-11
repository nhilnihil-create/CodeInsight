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
  ll N;
  cin>>N;
  string S;
  cin>>S;
  ll Q;
  cin>>Q;
  ll ans[Q];
  ll k;
  ll dnum, mnum;
  ll tmpans;
  ll dmap[N], mmap[N];
  for(ll i=0;i<Q;++i) {
    ans[i] = 0;
    cin>>k;
    dnum = 0;
    mnum = 0;
    for(ll j=0;j<N;++j) {
      dmap[j] = 0;
      mmap[j] = 0;
    }
    tmpans = 0;
    for(ll j=0;j<N;++j) {
      if(S[j]=='D') {
        dnum++;
        dmap[j]++;
      }
      if(S[j]=='M') {
        mnum++;
        mmap[j]++;
        tmpans += dnum;
      }
      if(S[j]=='C') {
        ans[i] += tmpans;
      }
      if(j-k+1>=0 && dmap[j-k+1]>0) {
        tmpans -= mnum;
        dnum--;
      }
      if(j-k+1>=0 && mmap[j-k+1]>0) {
        mnum--;
      }
    }
  }
  for(ll i=0;i<Q;++i) cout<<ans[i]<<endl;
}

