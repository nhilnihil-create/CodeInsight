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
  int d;
  cin >> d;
  if(d==25){
    printf("Christmas\n");
  }else if(d==24){
    printf("Christmas Eve\n");
  }else if(d==23){
    printf("Christmas Eve Eve\n");
  }else{
    printf("Christmas Eve Eve Eve\n");
  }
  return 0;
}
