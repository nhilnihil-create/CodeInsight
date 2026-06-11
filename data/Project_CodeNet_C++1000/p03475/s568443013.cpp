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
  int C[N-1], S[N-1], F[N-1];
  for(int i=0;i<N-1;++i) cin>>C[i]>>S[i]>>F[i];
  int ans[N];
  for(int i=0;i<N;++i) {
    ans[i] = 0;
    for(int j=i;j<N-1;++j) {
      if(ans[i]<=S[j]) ans[i] = S[j]+C[j];
      else ans[i] += (F[j]-ans[i]%F[j])%F[j]+C[j];
    } 
  }
  for(int i=0;i<N;++i) cout<<ans[i]<<endl;
}

