#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N,M;
  cin >> N >> M;

  int64_t ans;
  if(N==1 && M==1)      ans= 1;
  else if(N==1 || M==1) ans= max(N,M)-2;  // 角(2):表, 辺(3):裏           (括弧内は隣接マスの数)
  else                  ans= (N-2)*(M-2); // 角(4):表, 辺(6):表, 面(9):裏

  cout << ans << endl;
}