#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  int sum = 0, max = 0, max_num;
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
    if (max < L.at(i)) {
      max = L.at(i);
      max_num = i;
    }                  
  }
  for (int i = 0; i < N; i++) {
    if (i == max_num) continue;
    sum += L.at(i);
  }
  if (max >= sum) cout << "No" << endl;
  else cout << "Yes" << endl;
}