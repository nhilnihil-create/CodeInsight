//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define itn int
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sort(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=9e18;

int main(){
  int n,k; cin >> n >> k;
  set<pll> st;
  set<pll> st0;
  rep(i,n){
    ll x,y;
    cin >> x >> y;
    st.insert(pll(x,y));
  }
  for(auto a:st){
    for(auto b:st){
      st0.insert(pll(a.first,a.second));
      st0.insert(pll(a.first,b.second));
      st0.insert(pll(b.first,a.second));
      st0.insert(pll(b.first,b.second));
    }
  }
  ll ans=lnf;
  for(auto a:st0){
    for(auto b:st0){
      ll area=(a.first-b.first)*(a.second-b.second);
      int cnt=0;
      for(auto c:st){
        if(a.first<=c.first&&a.second<=c.second&&c.first<=b.first&&c.second<=b.second) cnt++;
      }
      if(cnt>=k) chmin(ans,area);
    }
  }
  cout << ans << endl;
}