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
  ll N, K;
  cin>>N>>K;
  ll A[N], B[N];
  for(int i=0;i<N;++i) cin>>A[i]>>B[i];
  vector<int> S;
  for(int i=31;i>=0;--i) {
    if((K&(1<<i))!=0) S.push_back(i);
  }
  ll ans = 0;
  ll tmpans;
  bool can;
  for(int i=0;i<S.size();++i) {
    tmpans = 0;
    for(int j=0;j<N;++j) {
      can = true;
      for(int k=31;k>S[i];--k) {
        if((K&(1<<k))==0 && (A[j]&(1<<k))!=0) can = false;
      }
      if((A[j]&(1<<S[i]))!=0) can = false;
      if(can) tmpans += B[j]; 
    }
    ans = max(ans, tmpans);
  }
  tmpans = 0;
  for(int i=0;i<N;++i) {
    can = true;
    for(int j=31;j>=0;--j) {
      if((K&(1<<j))==0 && (A[i]&(1<<j))!=0) can = false;
    }
    if(can) tmpans += B[i];
  }
  ans = max(ans, tmpans);
  cout<<ans<<endl;
}

