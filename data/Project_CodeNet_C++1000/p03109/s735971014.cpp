#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  string s;
  cin>>s;
  int a=(s[5]-'0')*10+(s[6]-'0');
  int b=(s[8]-'0')*10+(s[9]-'0');
  bool ok=true;
  
  if(a>4)ok=false;
  if(ok) cout<<"Heisei"<<endl;
  else cout<<"TBD"<<endl;
}







