#include <bits/stdc++.h>
using namespace std;
int main(){
  #define int long long
  int N;
  cin >> N;
  vector<int> b(N);
  unordered_map<int, int> mp;
  int B = -1;
  for (int i = 0; i < N; i++) {
    cin >> b.at(i);
  }
  for (int i = N - 1; i >= 0; i--){
    if (b.at(i) == i + 1) {
      B = i;
      break;
    }
  }
  stack<int> answer;
  for (int i = 0; i < N; i++)  {
    if (B == -1) {
      cout << -1 << endl;
      return 0;
    }
    answer.push(B + 1);
    for (int j = B; j < N - i - 1; j++) {
      b.at(j) = b.at(j + 1);
    }
    B = -1;
    for (int j = N - i - 2; j >= 0; j--){
      if (b.at(j) == j + 1) {
        B = j;
        break;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << answer.top() << endl;
    answer.pop();
  }
}