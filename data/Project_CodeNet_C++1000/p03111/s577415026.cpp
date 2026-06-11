#include <bits/stdc++.h>
using namespace std;
using lint = long long;
lint N, A, B, C;
vector<lint> l;
const lint INF = 1e18;

lint dfs(lint a, lint b, lint c, lint num){
  if(num == N){
    if(min({a, b, c}) > 0) return abs(A- a) + abs(B - b) + abs(C - c) - 30;
    else return INF;
  }
  lint x = dfs(a + l[num], b, c, num + 1) + 10;
  lint y = dfs(a, b + l[num], c, num + 1) + 10;
  lint z = dfs(a, b, c + l[num], num + 1) + 10;
  lint w = dfs(a, b, c, num + 1);
  return min({x, y, z, w});
}

signed main(){
  cin >> N >> A >> B >> C;
  l.resize(N);
  for(lint i = 0; i < N; i++) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
}