#include <bits/stdc++.h>
using namespace std;

int main(){
  int l,n = 0;
  cin >> l;

  // 頂点数
  while(1<<n <= l) n++;
  vector<vector<int>> ans;

  // 2進数の辺を作る
  for(int i=1; i<n; i++){
    ans.push_back({i, i+1, 1<<(i-1)});
    ans.push_back({i, i+1, 0});
  }

  // 今できている経路の最大長。これをL-1にするまで経路を足す。
  int now = (1<<(n-1)) - 1;

  for(int i=n-1;i>=1;i--){
    if(now == l-1) break;

    // 頂点iからのショートカット追加で増える経路数
    int gain = 1<<(i-1);

    if(now + gain <= l-1){
      ans.push_back({i,n,now+1});
      now += gain;
    }
  }
  int m = ans.size();
  cout << n << " " << m << endl;

  for(auto v : ans){
    cout << v[0] << " " << v[1] << " " << v[2] << endl;
  }
  return 0;
}
