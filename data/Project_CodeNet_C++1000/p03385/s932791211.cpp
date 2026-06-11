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
  int cnt[3];
  rep(i,0,3)cnt[i]=0;
  rep(i,0,3){
    
    if(s[i]=='a')cnt[0]=1;
    if(s[i]=='b')cnt[1]=1;
    if(s[i]=='c')cnt[2]=1;
  }
  if(cnt[0]==1&&cnt[1]==1&&cnt[2]==1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}