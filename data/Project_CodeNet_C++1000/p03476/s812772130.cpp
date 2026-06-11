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

const int INF = 100100;
int main() {
  vector<bool> p(INF+1,true);
  p[0] = p[1] = false;
  for(int i=2;i*i<=INF;++i){
    if(!p[i]) continue;
    for(int j=2*i;j<=INF;j+=i) p[j]=false;
  }
  vector<int> s(INF+1);
  rep(i,INF){
    s[i+1] = s[i];
    if(i&1 && p[i] && p[(i+1)/2]) s[i+1]++;
  }
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    cout << s[r+1]-s[l] << endl;
  }
}