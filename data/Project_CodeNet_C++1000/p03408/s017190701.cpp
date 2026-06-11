#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  int N;
  cin >> N;

  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s.at(i);
  }
  
  int M;
  cin >> M;

  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t.at(i);
  }
  
  // 計算
  map<string, int> ag;
  for (auto x : s) {
    if (ag.count(x)) {
      ag[x]++;
    } else {
      ag[x] = 1;
    }
  }
  
  for (auto x : t) {
    if (ag.count(x)) {
      ag[x]--;
    } else {
      ag[x] = -1;
    }
  }
  
  int m = INT_MIN;
  for (auto p : ag) {
    if (m < p.second) {
      m = p.second;
    }
  }
  
  // 出力
  println(max(0, m));
}