#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  int64_t answer;
  cin >> N;
  vector<int64_t> vec(N + 1);
  vec.at(0) = 2;
  vec.at(1) = 1;
  
  if (N == 1) {
    answer = 1;
  }
  if (N > 1) {
    for (int64_t i = 2; i < N + 1; i++) {
    vec.at(i) = vec.at(i-1) + vec.at(i-2);
    }
    answer = vec.at(N);
  }
   cout << answer << endl;
  
}