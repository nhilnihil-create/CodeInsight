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
  ll r,d,x;
  cin >> r >> d >> x;
  ll memo = x;
  rep(i,10){
    memo = r*memo - d;
    printf("%lld\n", memo);
  }
  return 0;
}
