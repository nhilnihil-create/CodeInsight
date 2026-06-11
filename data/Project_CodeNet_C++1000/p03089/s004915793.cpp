#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<long> data(N), ans;
  long flag;
  for(int i = 0; i < N; i++)cin >> data.at(i);
  for(int i = 0; i < N; i++){
    flag = 0;
    for(long j = data.size() - 1; j >= 0; j--){
      if(data.at(j) == j + 1){
        data.erase(data.begin() + j);
        ans.push_back(j + 1);
        flag = 1;
        break;
      }
    }
    if(flag == 0)break;
  }
  if(flag == 0)cout << -1 << endl;
  else {
    for(int i = ans.size() - 1; i >= 0; i--){
      cout << ans.at(i) << endl;
    }
  }
  return 0;
}