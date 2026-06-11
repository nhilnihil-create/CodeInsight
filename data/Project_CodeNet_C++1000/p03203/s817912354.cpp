#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

const int N = 200005;

int X[N];

int main() {
  int h,w,n;
  S2(h,w);
  S(n);
  rep(i,0,n) {
    int x,y;
    S2(x,y);
    if(!X[x] || y < X[x]) {
      X[x] = y;
    }
  }
  X[h + 1] = 1;
  if(h == 1) {
    P(1);
    return 0;
  }
  int mx = 0;
  rep(i,1,h+1) {
    if(X[i] != mx + 1) {
      mx++;
    }
    if(X[i + 1] && X[i + 1] <= mx) {
      P(i);
      break;
    }
  }
  return 0;
}
