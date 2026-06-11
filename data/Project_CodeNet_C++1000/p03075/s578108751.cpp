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
  int a[5];
  rep(i,5) cin >> a[i];
  int k;
  cin >> k;
  rep(i,5){
    for(int j = i+1; j < 5; j++){
      if(a[j] - a[i] > k){
        printf(":(\n");
        return 0;
      }
    }
  }
  printf("Yay!\n");
  return 0;
}
