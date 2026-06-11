#include <bits/stdc++.h>
using namespace std;
int main () {
  long N;
  cin >> N;
  vector<vector<long>> data(N, vector<long> (20));
  vector<long> sub(20);
  long A, count;
  for(int i = 0; i < N; i++){
    cin >> A;
    count = 0;
    while(A != 0){
      data.at(i).at(count) = A % 2;
      A /= 2;
      count++;
    }
  }
  for(int i = 0; i < 20; i++)sub.at(i) = data.at(0).at(i);
  long front = 0, back = 0, ans = 1, flag;
  count = 1;
  while(front != N - 1){
    flag = 1;
    for(int i = 0; i < 20; i++){
      if(data.at(front + 1).at(i) + sub.at(i) == 2){
        flag = 0;
        break;
      }
    }
    if(flag == 0){
      for(int i = 0; i < 20; i++){
        sub.at(i) -= data.at(back).at(i);
      }
      count--;
      back++;
    } else {
      front++;
      for(int i = 0; i < 20; i++){
        sub.at(i) += data.at(front).at(i);
      }
      count++;
      ans += count;
    }
  }
  cout << ans << endl;
  return 0;
}