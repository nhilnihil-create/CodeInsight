//A.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
const ll mod=1e9+7;
// const int imax = 100000;

int main(){
  string s;
  cin >> s;
  int r = 0;
  int b = 0;
  rep(i,s.length()){
    if(s[i]=='0') r++;
    else b++;
  }
  if(r>=b) printf("%d\n", 2*b);
  else printf("%d\n", 2*r);
  return 0;
}
