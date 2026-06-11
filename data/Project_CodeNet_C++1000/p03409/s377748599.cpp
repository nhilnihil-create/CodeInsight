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
  int n;
  cin >> n;
  vector<pii> red(n);
  rep(i,n) cin >> red[i].first >> red[i].second;
  set<pii> blue;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    blue.insert(pii(a,b));
  }
  sort(all(red));
  reverse(all(red));
  int ans=0;
  rep(i,n){
    int height=inf;
    pii tagc=pii(-1,-1);
    for(auto c:blue){
      if(red[i].first<c.first&&red[i].second<c.second){
        if(c.second-red[i].second<height){
          height=c.second-red[i].second;
          tagc=c;
        }
      }
    }
    if(tagc!=pii(-1,-1)){
      blue.erase(tagc);
      ans++;
    }
  }
  cout << ans << endl;
}
