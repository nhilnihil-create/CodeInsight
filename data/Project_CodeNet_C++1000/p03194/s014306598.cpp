#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <set>
using namespace std;
using ll = long long;

ll gcd(ll a,ll b) {
  if(a < b) gcd(b, a);
  unsigned r;
  while ((r=a%b)) {
    a = b;
    b = r;
  }
  return b;
}

int main(void){
    ll n,p;
    ll ans = 0;
    cin >> n >> p;
    for(int i=1;i<sqrt(p)+1;i++){
        if(p%i==0){
            ll x =  pow(i,n);
            if(p%x==0){
                if(i>ans){
                ans = i;
            }
            }
        }
    }
    if(n == 1){
        ans = p;
    }
    cout << ans << endl;
}