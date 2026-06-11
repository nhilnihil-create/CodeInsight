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
  int a,b,k;
  cin >> a >> b >> k;
  int cnt = 0;
  for(int i = 100; i >= 1; i--){
    if(a%i==0 && b%i==0){
      cnt++;
      if(k==cnt){
        printf("%d\n", i);
        return 0;
      }
    }

  }

    return 0;
}
