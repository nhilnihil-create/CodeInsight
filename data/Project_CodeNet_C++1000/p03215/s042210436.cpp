#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int main(){
  int n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> s(n+1);
  rep(i,n) s[i+1]=s[i]+a[i];
  vector<ll> b(0);
  rep(i,n){
    for(int j=i+1;j<=n;j++){
      b.push_back(s[j]-s[i]);
    }
  }
  ll x=0;
  for(int j=40;j>=0;j--){
    int cnt=0;
    rep(i,b.size()){
      if((b[i]&((1ll<<j)+x))==(1ll<<j)+x) cnt++;
    }
    if(cnt>=k) x+=1ll<<j;
  }
  cout << x << endl;
}