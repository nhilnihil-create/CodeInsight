#include <bits/stdc++.h>
using namespace std;

int N, K, answer = 0;
map<int, int> num_map;
vector<int> num_vector;

int main() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    num_map[num]++;
  }

  for (auto itr = num_map.begin(); itr != num_map.end(); itr++) {
    num_vector.push_back(itr->second);
  }
  sort(num_vector.begin(), num_vector.end());

  if (num_vector.size() > K)
    for (int i = 0; i < num_vector.size() - K; i++) answer += num_vector[i];

  cout << answer << endl;
}
