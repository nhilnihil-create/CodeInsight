#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);
typedef pair<int,int> P;
const int INF = 1001001001;

int n, A, B, C;
vector<int> l;
int dfs(int depth,int a,int b,int c){
  if(depth == n){
    if(a==0||b==0||c==0) return INF;
    else return  abs(a-A)+abs(b-B)+abs(c-C)-30;
  }
  int r0,r1,r2,r3;
      r0=dfs(depth+1,a,b,c);
      r1=dfs(depth+1,a+l[depth],b,c)+10;
      r2=dfs(depth+1,a,b+l[depth],c)+10;
      r3=dfs(depth+1,a,b,c+l[depth])+10;
      return min({r0,r1,r2,r3});
}
int main() {
  cin >> n >> A >> B >> C;
  l.resize(n);
  rep(i,n) cin >> l[i];
  cout << dfs(0,0,0,0) << endl;
  return 0;
}