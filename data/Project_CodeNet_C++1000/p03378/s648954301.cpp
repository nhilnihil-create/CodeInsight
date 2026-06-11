#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,m,x;
  cin >> n >> m >> x;
  int l=0,r=0;
  rep(i,m){
    int a;
    cin >> a;
    if(a<x) ++l; else ++r;
  }
  cout << min(l,r) << endl;
}
