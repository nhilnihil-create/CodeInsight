#include<bits/stdc++.h>
 
#define lol long long
#define gcd(x,y) __gcd(x,y)
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define fixed(x) fixed<<setprecision(x)
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
template <class A> inline lol abs(A &a) { return (a < 0 ? -a : a); }
bool inLine(int x,int y,int mx,int my){return (x>=0&&y>=0&&x<mx&&y<my);}
const lol inf=(1LL<<62);
const lol MOD=(1e9)+7;
const lol mod=998244353;
const int dx[]={1,0,-1,0,1,1,-1,-1};
const int dy[]={0,1,0,-1,1,-1,1,-1};
lol n,m,k;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >>n;
  vector<bool> ans(n+1,0);
  ans[0]=true;
  for(int i=4;i<=n;i+=4) ans[i]=true;
  for(int i=0;i<=n-7;i++){
    if(ans[i]) ans[i+7]=true;
  }
  if(ans[n]) cout <<"Yes\n";
  else cout <<"No\n";
  return (0);
}