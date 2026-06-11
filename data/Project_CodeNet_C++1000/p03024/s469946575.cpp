#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <istream>
#include <map>
#include <set>
#include <unordered_map>
#include <queue>
#include <functional>
#define rep0(i,n) for (int i = 0; i < (n); ++i)  //0スタート
#define rep1(i,n) for (int i = 1; i < (n); ++i)  //1スタート
#define REP(i,a,b) for (int i = a; i < (b); ++i)  //aからb - 1まで
#define mREP(i,a,b) for (int i = a; i > (b); --i)  //aからb - 1まで
#define p(x) cout<<x<<endl  //xを改行付きで出力
const int INF = 1000000007;  //最大値兼MOD
//  cin.tie(0);
//  ios::sync_with_stdio(false);
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main(){
  string s;
  cin>>s;
  int count = 0;
  rep0(i,s.length()){
    if(s[i] == 'o')count++;
  }
  if(count + (15 - (int)s.length()) > 7)p("YES");
  else p("NO");
  return 0;
}