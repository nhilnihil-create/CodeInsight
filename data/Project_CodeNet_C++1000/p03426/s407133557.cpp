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
  int h,w,d;
  cin >> h >> w >> d;
  vector<P> p(h*w);
  rep(i,h)rep(j,w){
    int a;
    cin >> a;
    p[a-1] = P(i,j);
  }
  vector<ll> s(h*w);
  rep(i,h*w-d){
    s[i+d] += s[i] + abs(p[i].first-p[i+d].first) + abs(p[i].second-p[i+d].second);
  }
  int q;
  cin >> q;
  rep(_,q){
    int l,r;
    cin >> l >> r;
    --l; --r;
    cout << s[r]-s[l] << endl;
  }
}