#include <algorithm>  // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <bitset>     // bitset
#include <cctype>     // isupper, islower, isdigit, toupper, tolower
#include <cstdint>    // int64_t, int*_t
#include <cstdio>     // printf
#include <deque>      // deque
#include <iomanip>    // fixed, setprecision
#include <iostream>   // cout, endl, cin
#include <map>        // map
#include <queue>      // queue, priority_queue
#include <set>        // set
#include <stack>      // stack
#include <string>     // string, to_string, stoi
#include <tuple>      // tuple, make_tuple
#include <unordered_map>  // unordered_map
#include <unordered_set>  // unordered_set
#include <utility>        // pair, make_pair
#include <vector>         // vector
using namespace std;

int main() {
  int N, M, C, correct = 0, score, A;
  cin >> N >> M >> C;
  vector<int> B(M);
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
  }
  for (int i = 0; i < N; i++) {
    score = C;
    for (int j = 0; j < M; j++) {
      cin >> A;
      score += A * B[j];
    }
    if (score > 0) correct++;
  }
  cout << correct << endl;
}
