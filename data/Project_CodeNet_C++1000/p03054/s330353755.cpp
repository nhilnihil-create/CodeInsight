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

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  int p,q;
  cin >> q >> p;
  string s,t;
  cin >> s >> t;

  int pos=p, cur=p;
  rep(i,n){
    if(s[i]=='R'){
      cur++;
      pos = max(pos,cur);
    }
    if(t[i]=='L'&&1<cur) cur--;
  }
  if(w<pos){ cout << "NO" << endl; return 0; }

  pos=p, cur=p;
  rep(i,n){
    if(s[i]=='L'){
      cur--;
      pos = min(pos,cur);
    }
    if(t[i]=='R'&&cur<w) cur++;
  }
  if(pos<=0){ cout << "NO" << endl; return 0; }

  pos=q, cur=q;
  rep(i,n){
    if(s[i]=='D'){
      cur++;
      pos = max(pos,cur);
    }
    if(t[i]=='U'&&1<cur) cur--;
  }
  if(h<pos){ cout << "NO" << endl; return 0; }

  pos=q, cur=q;
  rep(i,n){
    if(s[i]=='U'){
      cur--;
      pos = min(pos,cur);
    }
    if(t[i]=='D'&&cur<h) cur++;
  }
  if(pos<=0){ cout << "NO" << endl; return 0; }
  cout << "YES" << endl;
  return 0;
}