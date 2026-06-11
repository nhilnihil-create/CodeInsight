#include<iostream>
using namespace std;

int N, cnt;

void dfs(int depth, int val, bool has7, bool has5, bool has3) {
  if (val > 0 && has7 && has5 && has3 && val <= N) cnt++;
  if (depth < 9) {
    dfs(depth+1, val*10+7, true, has5, has3);
    dfs(depth+1, val*10+5, has7, true, has3);
    dfs(depth+1, val*10+3, has7, has5, true);
  }
}

int main() {
  cin >> N;
  cnt = 0;
  dfs(0, 0, false, false, false);
  cout<<cnt<<endl;
}