//#define _GLIBCXX_DEBUG
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
  int h,w,d;
  cin >> h >> w >> d;
  map<int,pii> mp;
  for(int i=1;i<=h;i++)for(int j=1;j<=w;j++){
    int a; cin >> a;
    mp[a]=pii(i,j);
  }
  vector<ll> s(1+h*w+d);
  for(int i=1;i<=h*w;i++){
    s[i+d]=s[i]+abs(mp[i+d].first-mp[i].first)+abs(mp[i+d].second-mp[i].second);
  }
  int q; cin >> q;
  vector<ll> ans(q);
  rep(i,q){
    int l,r; cin >> l >> r;
    ans[i]=s[r]-s[l];
  }
  rep(i,q) cout << ans[i] << endl;
}