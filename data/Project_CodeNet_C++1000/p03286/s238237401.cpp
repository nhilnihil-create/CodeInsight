#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  ll N;
  cin>>N;
  ll keta;
  ll two;
  ll sum;
  vector<ll> ans(1000, 0);
  if(N==0) {
    cout<<0<<endl;
    return 0;
  }
  while(N!=0){
    if(N>0) {
      two = 1;
      keta = -1;
      sum = 0;
      while(sum<N) {
        sum += two;
        two *= 4;
        keta += 2;
      }
      ans[keta] = 1;
      two = 1;
      for(ll i=0;i<keta-1;++i) {
        two *= -2;
      }
      N -= two;
    }
    else {
      two = 2;
      keta = 0;
      sum = 0;
      while(sum>N) {
        sum -= two;
        two *= 4;
        keta += 2;
      }
      ans[keta] = 1;
      two = 1;
      for(ll i=0;i<keta-1;++i) {
        two *= -2;
      }
      N -= two;
    }
  }
  bool aru = false;
  for(int i=1000-1;i>0;--i) {
    if(aru) cout<<ans[i];
    else if(ans[i]==1) {
      aru = true;
      cout<<ans[i]; 
    }
  }
  cout<<endl;
}

