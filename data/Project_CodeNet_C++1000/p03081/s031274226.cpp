#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
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
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<pair<char,char>> a(q);
  rep(i,q){
    cin >> a[i].F >> a[i].S;
  }
  int ok=-1,ng=n+1,mid=(ok+ng)/2;
  int pos=mid;
  while(ng-ok>1){
    mid=(ok+ng)/2;
    pos=mid;
    rep(i,q){
      if(0<=pos && pos<n && s[pos]==a[i].F){
        if(a[i].S=='R'){ pos++; } else { pos--; }
      }
    }
    if(pos<n){ ok=mid; }else{ ng=mid; }
  }
  pos = ok;

  ok=n,ng=-1,mid=(ok+ng)/2;
  int pos2=mid;
  while(ok-ng>1){
    mid=(ok+ng)/2;
    pos2=mid;
    rep(i,q){
      if(0<=pos2 && pos2<n && s[pos2]==a[i].F){
        if(a[i].S=='R'){ pos2++; } else { pos2--; }
      }
    }
    if(0<=pos2){ ok=mid; }else{ ng=mid; }
  }
  pos2 = ok;

  int ans = max(pos-pos2+1,0);
  cout << ans << endl;
  return 0;
}