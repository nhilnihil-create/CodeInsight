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
// const int INF = 1000000;

int main(){
  int n;
  cin >> n;
  int p[n];
  int a;
  rep(i,n){
    cin >> a;
    p[i] = -a;
  }
  sort(p,p+n);
  int ans;
  ans = 0;
  ans -= p[0]/2;
  for(int i = 1; i < n; i++){
    ans -= p[i];
  }
  printf("%d\n", ans);
  return 0;
}
