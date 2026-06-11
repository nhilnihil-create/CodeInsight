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
  int b[] = {0,1,2,3,4};
  int mtime = 1e5;
  int time;
  rep(i,120){
    time = 0;
    rep(j,5){
      time += a[b[j]];
      if(time%10!=0 && j!=4){
        time += (10-time%10);
      }
    }
    mtime = min(mtime,time);
    next_permutation(b,b+5);
  }
  printf("%d\n", mtime);

  return 0;
}
