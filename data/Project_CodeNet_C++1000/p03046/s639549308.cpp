#include <bits/stdc++.h>
using namespace std;
int main(){
  int M, K;
  cin >> M >> K;
  if (M == 1){
    if (K == 0){
      cout << "0 0 1 1" << endl;
    } else {
      cout << -1 << endl;
    }
  } else {
    if (K >= (1 << M)){
      cout << -1 << endl;
    } else {
      vector<int> c;
      for (int i = 0; i < (1 << M); i++){
        if (i != K){
          c.push_back(i);
        }
      }
      vector<int> ans = c;
      ans.push_back(K);
      reverse(c.begin(), c.end());
      for (int x : c){
        ans.push_back(x);
      }
      ans.push_back(K);
      int sz = ans.size();
      for (int i = 0; i < sz; i++){
        cout << ans[i];
        if (i < sz - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}