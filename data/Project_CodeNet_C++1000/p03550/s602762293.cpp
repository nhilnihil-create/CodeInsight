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

int n;
vector<int> a,dpx,dpy;
int dfs(int i,int s,int t, bool b){
  if(i==n) return abs(t-s);
  int res;
  if(b){
    if(dpx[i]>=0) return dpx[i];
    res = 0;
    for(int j=i;j<n;++j){
      res = max(res,dfs(j+1,a[j],t,!b));
    }
    dpx[i] = res;
  }else{
    if(dpy[i]>=0) return dpy[i];
    res = 1e9;
    for(int j=i;j<n;++j){
      res = min(res,dfs(j+1,s,a[j],!b));
    }
    dpy[i] = res;
  }
  return res;
}

int main(){
  int s,t;
  cin >> n >> s >> t;
  a = vector<int>(n);
  rep(i,n) cin >> a[i];
  dpx = dpy = vector<int>(n,-1);
  cout << dfs(0,s,t,true) << endl;;
}