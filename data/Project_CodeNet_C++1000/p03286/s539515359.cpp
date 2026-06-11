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
  ll two=1, two1=0, two2=0;
  for(int i=0;i<40;++i) {
    if(i%2==0) two1 += two;
    else two2 -= two;
    two *= 2;
  }
  vector<int> ans(40);
  for(int i=0;i<40;++i) {
    two /= 2;
    if(i%2==0) {
      if(two2<=N && N<two2+two) {
        ans[i] = 1;
        N += two;
      }
      else ans[i] = 0;
      two2 += two;
    }
    else {
      if(two1-two<N && N<=two1) {
        ans[i] = 1;
        N -= two;
      }
      else ans[i] = 0;
      two1 -= two;
    }
  }
  bool zero = true;
  for(int i=0;i<40;++i) {
    if(zero) {
      if(ans[i]==1) {
        zero = false;
        cout<<ans[i];
      }
    }
    else cout<<ans[i];
  }
  if(zero) cout<<0;
  cout<<endl;
}
