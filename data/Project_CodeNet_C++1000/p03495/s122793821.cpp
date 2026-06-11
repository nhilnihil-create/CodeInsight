#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  // 計算
  map<int, int> ret;
  
  for (auto a : A) {
    if (ret.count(a)) {
      ret[a]++;
    } else {
      ret[a] = 1;
    }
  }
  
  int key_num = ret.size();
  int num = key_num - K; // 何キー削除すれば良いか
  
  multimap<int, int> r;
  
  for (auto x : ret) {
    r.emplace(pair<int, int>{ x.second, x.first });
  }
  
  int z = 0;
  for (auto x : r) {
    if (num <= 0) {
      break;
    }
    z += x.first;
    num--;
  }
    
  // 出力
  println(z);
}