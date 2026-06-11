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
  ll M, K;
  cin>>M>>K;
  if(K==0) {
    for(int i=0;i<(1<<M);++i) {
      cout<<i<<" "<<i<<" ";
    }
    cout<<endl;
    return 0;
  }
  ll tmp=0;
  for(int i=0;i<(1<<M);++i) {
    if(i==K) continue;
    tmp ^= i;
  }
  if(tmp!=K) {
    cout<<-1<<endl;
    return 0;
  }
  cout<<0<<" "<<K<<" "<<0<<" ";
  for(int i=1;i<(1<<M);++i) {
    if(i==K) continue;
    cout<<i<<" ";
  }
  cout<<K<<" ";
  for(int i=(1<<M)-1;i>0;--i) {
    if(i==K) continue;
    cout<<i<<" ";
  }
  cout<<endl;
}

