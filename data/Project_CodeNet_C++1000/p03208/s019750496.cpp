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
  ll n,k;
  cin >> n >> k;
  ll h[n];
  rep(i,n) cin >> h[i];
  sort(h,h+n);
  ll dif[n-k+1];
  rep(i,n-k+1){
    dif[i] = h[i+k-1] - h[i];
  }
  sort(dif,dif+n-k+1);
  printf("%lld\n", dif[0]);
  return 0;
}
