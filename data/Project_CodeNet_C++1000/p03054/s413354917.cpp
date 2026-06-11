#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int h,w,n,x,y;
  cin >> h >> w >> n >> x >> y;
  string s,t;
  cin >> s >> t;

  int cntr = y, cntl = y, cntu = x, cntd = x;
  rep(i,n){
    if(s[i]=='R'){ cntr++; }
    if(s[i]=='L'){ cntl--; }
    if(s[i]=='D'){ cntu++; }
    if(s[i]=='U'){ cntd--; }
    if(cntr > w){ cout << "NO" << ln; return 0;}
    if(cntl < 1){ cout << "NO" << ln; return 0;}
    if(cntu > h){ cout << "NO" << ln; return 0;}
    if(cntd < 1){ cout << "NO" << ln; return 0;}
    if(t[i]=='L'&&cntr>1){ cntr--; }
    if(t[i]=='R'&&cntl<w){ cntl++; }
    if(t[i]=='U'&&cntu>1){ cntu--; }
    if(t[i]=='D'&&cntd<h){ cntd++; }
  }

  
  cout << "YES" << ln;
  return 0;
}