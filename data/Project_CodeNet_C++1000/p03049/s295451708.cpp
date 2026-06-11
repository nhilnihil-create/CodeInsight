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
  int N;
  cin>>N;
  string S[N];
  for(int i=0;i<N;++i) cin>>S[i];
  int ans = 0;
  int anum=0, bnum=0, abnum=0;
  for(int i=0;i<N;++i) {
    for(int j=0;j<S[i].size()-1;++j) {
      if(S[i][j]=='A' && S[i][j+1]=='B') ans++;
    }
    if(S[i][0]=='B' && S[i][S[i].size()-1]=='A') abnum++;
    else if(S[i][S[i].size()-1]=='A') anum++;
    else if(S[i][0]=='B') bnum++;
  }
  if(anum>0 || bnum>0) {
    ans += min(abnum+anum, abnum+bnum);
  }
  else if(abnum>0) ans += abnum-1;
  cout<<ans<<endl;
}

