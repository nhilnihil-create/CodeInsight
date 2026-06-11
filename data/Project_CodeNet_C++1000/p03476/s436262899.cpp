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
  bool prime[100005];
  bool like[100005];
  for(int i=0;i<100005;++i) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
  for(int i=2;i<100005;++i) {
    if(prime[i]==false) continue;
    for(int j=2;i*j<100005;++j) {
      prime[i*j] = false;
    }
  }
  for(int i=0;i<100005;++i) {
    if(i%2==1 && prime[i] && prime[(i+1)/2]) like[i] = true;
    else like[i] = false;
  }
  int likenum[100005];
  for(int i=0;i<100005;++i) {
    if(like[i]) likenum[i] = 1;
    else likenum[i] = 0;
  }
  for(int i=1;i<100005;++i) likenum[i] += likenum[i-1];
  int Q;
  cin>>Q;
  int l, r;
  int ans[Q];
  for(int i=0;i<Q;++i) {
    cin>>l>>r;
    ans[i] = likenum[r]-likenum[l-1];
  }
  for(int i=0;i<Q;++i) cout<<ans[i]<<endl;
}

