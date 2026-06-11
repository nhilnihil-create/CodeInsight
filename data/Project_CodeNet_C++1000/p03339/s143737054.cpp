#include <bits/stdc++.h>

#define rep(i, n) for(int i=0; i < n; i++)
#define REP(i, n, m) for(int i=n; i < m; i++)
#define reps(i, n) for(int i=1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

using namespace std;
using ll=long long;

ll mod=1000000007;

const ll INF = 1LL << 60;

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main() {
  int n;cin>>n;
  string s;cin>>s;
  string t=s;
  reverse(ALL(t));
  int l[n],r[n],x,y;
  l[0]=x=0;r[0]=y=0;
  reps(i,n-1){
    if(s[i-1]=='W')x++;
    if(t[i-1]=='E')y++;
    l[i]=x;r[i]=y;
  }
  int ans=n+1;
  rep(i,n)chmin(ans,l[i]+r[n-i-1]);
  cout <<ans;
}