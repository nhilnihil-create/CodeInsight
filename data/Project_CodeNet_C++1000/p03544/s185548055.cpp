#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  // N × (3 × 3)要素の配列を宣言
  /* vector<vector<vector<char>>> data(N, vector<vector<char>>(3, vector<char>(3))); */
  // int型の2次元配列(3×4要素の)の宣言
  /* vector<vector<int>> data(3, vector<int>(4)); */
  int N;
  cin >> N;
  int64_t result = 1;
  int64_t before = 2;
  int64_t tmp;
  for(int i = 1; i < (int)N; i++) {
    tmp = result;
    result += before;
    before = tmp;
  }

  cout << result << endl;
}
