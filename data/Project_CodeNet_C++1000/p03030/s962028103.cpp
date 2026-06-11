#include <bits/stdc++.h>
#include <tuple>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
bool custom_sort(tuple<string, int, int> t1, tuple<string, int, int> t2) {
  if(get<0>(t1) == get<0>(t2)) {
    return get<1>(t1) > get<1>(t2);
  } else {
    return get<0>(t1) < get<0>(t2);
  }
}

int main() {
  // N × (3 × 3)要素の配列を宣言
  /* vector<vector<vector<char>>> data(N, vector<vector<char>>(3, vector<char>(3))); */
  // int型の2次元配列(3×4要素の)の宣言
  /* vector<vector<int>> data(3, vector<int>(4)); */
  int N;
  cin >> N;
  string a;
  int b;
  vector<tuple<string, int, int>> vec;

  rep(i, N) {
    cin >> a >> b;
    vec.push_back(make_tuple(a, b, i+1));
  }

  sort(vec.begin(), vec.end(), custom_sort);

  for(tuple<string, int, int> t : vec) {
    cout << get<2>(t) << endl;
  }
}
