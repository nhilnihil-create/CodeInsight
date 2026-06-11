#include <bits/stdc++.h>
typedef long long LL;
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;
LL p = 1000000007ll;

vector<LL> dx, dy;
vector<LL> dxsum(1), dysum(1);
map<pair<LL,LL>,LL> memo;

LL solve(LL x, LL n)
{
  if(abs(x)>dxsum.back()-dxsum[n]) return 0;
  if(abs(x)==dxsum.back()-dxsum[n]) return 1;
  if(n==dx.size()) {
    if(x==0) return 1;
    else return 0;
  }
  auto key = make_pair(x,n);
  if(memo.count(key)) return memo[key];
  memo[key] = max(solve(x-dx[n], n+1), solve(x+dx[n], n+1));
  return memo[key];
}

int main(void)
{
  string s;
  LL x,y;
  cin >> s >> x >> y;
  s.push_back('T');
  LL ix=0;
  LL mode = 2, tmp = 0;
  for(auto c:s) {
    if(c=='F') {
      if(mode == 2) ++ix;
      else ++tmp;
    } else {
      if(tmp) {
        if(mode == 0) dx.push_back(tmp);
        else dy.push_back(tmp);
        tmp = 0;
      }
      mode = (mode+1)%2;
    }
  }
  for(auto z:dx) dxsum.push_back(dxsum.back()+z);
  for(auto z:dy) dysum.push_back(dysum.back()+z);
  LL flag = 0;
  flag += solve(x-ix,0);
  dx = dy;
  dxsum = dysum;
  memo.clear();
  flag += solve(y,0);
  cout << (flag==2?"Yes":"No") << endl;
  return 0;
}
