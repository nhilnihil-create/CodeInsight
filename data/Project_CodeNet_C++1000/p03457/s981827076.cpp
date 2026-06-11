#include <bits/stdc++.h>
using namespace std;

bool check(int tn, int tn_1, int xn, int xn_1, int yn, int yn_1){
  int t = tn_1 - tn, x = xn_1 - xn, y = yn_1 - yn, length;
  length = abs(x) + abs(y);
  bool ans = false;
  if(t % 2 == 0){
    if (length <= t && length % 2 == 0){
      ans = true;
    }
  }
  if(t % 2 == 1){
    if (length <= t && length % 2 == 1){
      ans = true;
    }
  }
  return ans;
}

int main(){
  int N;
  cin >> N;
  bool tmp_bool, ans_bool = true;
  vector<vector<int>> vec(N, vector<int>(3));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 3; j++){
      cin >> vec.at(i).at(j);
    }
  }
  tmp_bool = check(0, vec.at(0).at(0), 0, vec.at(0).at(1), 0, vec.at(0).at(2));
  if (tmp_bool == false) ans_bool = false;
  for(int i = 0; i < N - 1; i++){
    tmp_bool = check(vec.at(i).at(0), vec.at(i + 1).at(0), vec.at(i).at(1), vec.at(i + 1).at(1), vec.at(i).at(2), vec.at(i + 1).at(2));
    if (tmp_bool == false) ans_bool = false;
  }
  if (ans_bool) cout << "Yes";
  else cout << "No";
  return 0;
}
