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
  string S;
  cin>>S;
  map<char, ll> amap;
  vector<char> arr;
  for(int i=0;i<S.size();++i) {
    if(amap[S[i]]==0) arr.push_back(S[i]);
    amap[S[i]]++;
  }
  ll ans = 1;
  for(int i=0;i<arr.size();++i) {
    ans *= amap[arr[i]]+1;
    ans %= mod;
  }
  cout<<(ans-1+mod)%mod<<endl;
}

