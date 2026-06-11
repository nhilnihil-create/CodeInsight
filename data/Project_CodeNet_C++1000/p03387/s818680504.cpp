#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;//
  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];//v = {a, b, c}
  while(v[0] != v[1] || v[0] != v[2]) {
    sort(v.begin(), v.end());
    int x = v[2] - v[1];
    ans += x;
    v[1] = v[2];
    v[0] += x;
    int y = v[2] - v[0];
    if(y % 2 == 0) {
      ans += y / 2;
      v[0] = v[2];
    }else {//差が奇数
      ans += (y + 1) / 2;
      v[0] += (y + 1);
    }
  }
  cout << ans;
}