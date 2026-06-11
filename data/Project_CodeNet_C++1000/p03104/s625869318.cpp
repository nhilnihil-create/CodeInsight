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

ll check(ll a, ll b, ll digit){
  ll div = pow(2,digit);
  ll cnt = 0;
  if(div - (a%div) + a <= b){
    if(a%(2*div) >= div) cnt += (div-(a%div))%2;
    if(b%(2*div) >= div) cnt += (b%div+1)%2;
    cnt %= 2;
  }else{
    if(a%(2*div) >= div) cnt += (b-a+1)%2;
  }
  return cnt;
}


int main(){
  ll a,b;
  cin >> a >> b;
  ll digit = 0;
  ll memo = b;
  while(memo > 0){
    memo /= 2;
    digit++;
  }
  ll ans = 0;
  if(a%2==0){
    if(((b-a+1)/2)%2 != 0) ans++;
  }else{
    if(((b-a+1+1)/2)%2 != 0) ans++;
  }
  memo = 2;
  for(int i = 1; i < digit; i++){
    ans += check(a,b,i)*memo;
    memo *= 2;
  }
  printf("%lld\n", ans);
  return 0;
}
