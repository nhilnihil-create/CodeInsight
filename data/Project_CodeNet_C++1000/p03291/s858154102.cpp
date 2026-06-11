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

ll ADP[100005], ABDP[100005], ABCDP[100005];

int main() {
  string S;
  cin>>S;
  ll num = 1;
  if(S[0]=='A') ADP[0] = 1;
  if(S[0]=='?') {
    ADP[0] = 1;
    num *= 3;
  }
  for(int i=1;i<S.size();++i) {
    if(S[i]=='A') {
      ADP[i] = (ADP[i-1]+num)%mod;
      ABDP[i] = ABDP[i-1];
      ABCDP[i] = ABCDP[i-1];
    }
    if(S[i]=='B') {
      ADP[i] = ADP[i-1];
      ABDP[i] = (ADP[i-1]+ABDP[i-1])%mod;
      ABCDP[i] = ABCDP[i-1];
    }
    if(S[i]=='C') {
      ADP[i] = ADP[i-1];
      ABDP[i] = ABDP[i-1];
      ABCDP[i] = (ABCDP[i-1]+ABDP[i-1])%mod;
    }
    if(S[i]=='?') {
      ADP[i] = (ADP[i-1]*3%mod+num)%mod;
      ABDP[i] = (ADP[i-1]+ABDP[i-1]*3%mod)%mod;
      ABCDP[i] = (ABCDP[i-1]*3%mod+ABDP[i-1])%mod;
      num *= 3;
      num %= mod;
    }
  }
  cout<<ABCDP[S.size()-1]<<endl;
}

