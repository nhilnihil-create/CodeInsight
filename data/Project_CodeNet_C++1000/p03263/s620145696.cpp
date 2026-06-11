#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<cmath>
#include<cstdint>
 
#define INF 1e9
#define LINF 1e19
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
     
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
using PP = pair<P, P>;
     
const ll MOD = 1e9 + 7;
const ll ZER = 0;
 


int main(){
  int h, w;
  cin >> h >> w;
  vector<vector<int>> fld(h, vector<int>(w));
  rep(i, h)rep(j, w)cin >> fld[i][j];
  queue<PP> que;
  rep(i, h){
    rep(j, w){
      if(fld[i][j] % 2 == 0)continue;
      if(j != w - 1){
        que.push(PP(P(i, j), P(i, j + 1)));
        fld[i][j + 1]++;
      }
      else if(i != h - 1){
        que.push(PP(P(i, j), P(i + 1, j)));
        fld[i + 1][j]++;
      }
    }
  }
  cout << que.size() << endl;
  while(!que.empty()){
    P p = que.front().first, q = que.front().second;
    int y = p.first, x = p.second, yy = q.first, xx = q.second;
    que.pop();
    y++;x++;yy++;xx++;
    cout << y << " " << x << " " << yy << " " << xx << endl;
  }
}
 