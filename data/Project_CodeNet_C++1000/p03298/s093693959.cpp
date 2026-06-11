#ifdef __LOCAL
  #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b) {if(a<b) {a=b; return true;} return false;}
template<typename T> bool chmin(T &a,T b) {if(a>b) {a=b; return true;} return false;}
#define itn int
#define fi first
#define se second
#define intmax numeric_limits<int>::max()
#define llmax numeric_limits<ll>::max()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>=1;i--)
#define all(vec) vec.begin(),vec.end()
#define sortt(vec) sort((vec).begin(),(vec).end())
#define rsort(vec) sort((vec).rbegin(), (vec).rend())
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<string,string> pss;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;
const ll lnf=1ll<<60;

int main(){
  itn n; cin >> n;
  string s; cin >> s;
  string t=s.substr(n);
  string u=s.substr(0,n);
  reverse(all(u));
  map<pss,itn> mp;
  rep(bit,(1ll<<n)){
    string red;
    string blue;
    rep(i,n){
      if(bit&(1ll<<i)) red+=t[i];
      else blue+=t[i];
    }
    mp[pss(red,blue)]++;
  }
  ll ans=0;
  rep(bit,(1ll<<n)){
    string red;
    string blue;
    rep(i,n){
      if(bit&(1ll<<i)) red+=u[i];
      else blue+=u[i];
    }
    ans+=mp[pss(blue,red)];
  }
  cout << ans << endl;
}