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
  ll n;
  cin >> n;
  ll a[5];
  ll b[5];
  rep(i,5){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b,b+5);
  ll memo;
  rep(i,5){
    if(a[i] == b[0]){
      memo = i;
      break;
    }
  }
  ll cnt = memo;
  cnt += (n+a[memo]-1)/a[memo];
  cnt += 4 - memo;
  printf("%lld\n", cnt);
  return 0;
}
