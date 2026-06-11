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
  int K;
  cin>>K;
  ll A[K];
  for(int i=0;i<K;++i) cin>>A[i];
  ll mini=2, maxi=2;
  bool can = true;
  for(int i=K-1;i>=0;--i) {
    mini += (A[i]-mini%A[i])%A[i];
    if(mini>maxi) can = false;
    maxi = maxi/A[i]*A[i]+A[i]-1;
  }
  if(can) cout<<mini<<" "<<maxi<<endl;
  else cout<<-1<<endl;
}

