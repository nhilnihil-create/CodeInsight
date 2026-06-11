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
  int N;
  cin>>N;
  string S;
  cin>>S;
  map<char, ll> amap;
  vector<char> arr;
  for(int i=0;i<S.size();++i){
    if(amap[S[i]]==0) arr.push_back(S[i]);
    amap[S[i]]++;
  }
  int siz = arr.size();
  int n = siz/2;
  vector<ll> arr1, arr2;
  ll tmp;
  for(int bit=0;bit<(1<<n);++bit){
    tmp = 1;
    for(int i=0;i<n;++i){
      if((bit&(1<<i))!=0) {
        tmp *= amap[arr[i]];
        tmp %= mod;
      }
    }
    arr1.push_back(tmp);
  }
  for(int bit=0;bit<(1<<(siz-n));++bit){
    ll tmp = 1;
    for(int i=0;i<siz-n;++i){
      if((bit&(1<<i))!=0){
        tmp *= amap[arr[i+n]];
        tmp %= mod;
      }
    }
    arr2.push_back(tmp);
  }
  ll ans = 0;
  for(int i=0;i<arr1.size();++i){
    for(int j=0;j<arr2.size();++j){
      ans += arr1[i]*arr2[j]%mod;
      ans %= mod;
    }
  }
  cout<<ans-1<<endl;
}
