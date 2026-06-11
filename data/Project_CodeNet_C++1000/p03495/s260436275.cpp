#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  unordered_map<int, int> map;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (map.count(A[i]) > 0) {
      map[A[i]]++;
    } else {
      map[A[i]] = 1;
    }
  }
  if (map.size() < K) {
    cout << "0" << endl;
    return 0;
  }

  vector<int> count;
  for (auto p : map) {
    count.push_back(p.second);
  }

  int sum = 0;
  sort(count.begin(), count.end(), greater<int>());
  for (int i = 0; i < K; i++) {
    sum += count[i];
  }
  cout << N - sum << endl;

  return 0;
}
