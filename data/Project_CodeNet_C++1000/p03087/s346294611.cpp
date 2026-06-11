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


int main(){
  int n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  int a[n] = {0};
  rep(i,n-1){
    a[i+1] += a[i];
    if(s.substr(i,2) == "AC") a[i+1]++;
  }
  int l[q];
  int r[q];
  rep(i,q) cin >> l[i] >> r[i];
  rep(i,q){
    // cin >> l >> r;
    printf("%d\n", a[r[i]-1] - a[l[i]-1]);
  }
  return 0;
}
