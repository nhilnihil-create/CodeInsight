#include <iostream>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <numeric>
#include <cmath>
#include <cctype>

using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,x); REP(i,sizeof(a)){ (a)[i]=(x); }
#define CINA(a,n); REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x); REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m); REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"

#define umap unordered_map
//cout << setfill('0') << right << setw(4) << 12; // "0012"
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
int keta_wa(ll x){ if(x<10){return x;} else{return keta_wa(x/10) + x%10;} }
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll sum(ll a[],ll N){ return accumulate(a,a+N,0LL);}
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}

struct mn{
  int y,x,_y,_x;
};
int H,W,y,x,_y,_x; 
int a[1000][1000];
int ans = 0;
vector<mn> v;
void move(int y,int x,int _y, int _x, int a[][1000]){
  a[y][x] -= 1;
  a[_y][_x] += 1;
  ++ans;
  v.push_back( {y+1,x+1,_y+1,_x+1} );
}

int main(){
  cin>>H>>W;
  CINA2(a,H,W);
  
  for(y=0;y<H;++y){
    for(x=0;x<W-1;++x){
      if(a[y][x]%2==1){
        _y = y;
        _x = x+1;
        move(y,x,_y,_x,a);
      }
    }
    if(y+1==H){ break;}
    if(a[y][x]%2==1){
      _x = x;
      _y = y+1;
      move(y,x,_y,_x,a);
    }
    ++y;
    for(x=W-1;x>0;--x){
      if(a[y][x]%2==1){
        _y = y;
        _x = x-1;
        move(y,x,_y,_x,a);
      }
    }
    if(y+1==H){break;}
    if(a[y][x]%2==1){
      _x = x;
      _y = y+1;
      move(y,x,_y,_x,a);
    }
  }
  cout << ans << "\n";
  for(mn m:v){
    printf("%d %d %d %d\n",m.y,m.x,m._y,m._x);
  }
}