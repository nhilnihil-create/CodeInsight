#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
#include <deque>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
ll f(ll n){
  int ret = 0;
  while(n){
    ret += n % 10;
    n /= 10;
  }
  return ret;
}
double g(ll n){
  return (double)n / f(n);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll K;
  cin>>K;
  // 候補を全列挙
  vector<ll> v;
  ll ten = 1;
  FOR(i,0,15){
    FOR(j,1,150){
      v.push_back(j*ten-1);
    }
    ten *= 10;
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  FOR(i,1,v.size()){
    bool ok = true;
    FOR(j,i+1,v.size()){
      if(g(v[i]) > g(v[j])){
        ok = false;
        break;
      }
    }
    if(ok) {
      cout << v[i] << endl;
      K--;
      if(K==0) return 0;
    }
  }
}