#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A1(N);
  vector<int> A2(N);
  for (int i = 0; i < N; i++) cin >> A1.at(i);
  for (int i = 0; i < N; i++) cin >> A2.at(i);
  int A2sum = 0;
  for (int i = 0; i < N; i++) A2sum += A2.at(i);
  int temp = A1.at(0) + A2sum;
  int ans = temp;
  for (int i = 0; i < N - 1; i++){
    temp = temp + A1.at(i + 1) - A2.at(i);
    ans = max(ans, temp);
  }
  cout << ans << endl;
}
