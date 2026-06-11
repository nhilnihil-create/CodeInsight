#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> P(N);
  map<int, int> mp;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    mp[P[i]] = i;
  }
  vector<int> vec;
  for(int i = 1; i <= N; i++) {
    vec.push_back(mp[i]);
  }
  int max_len, cnt = 0, grad = -1;
  for(int i = 0; i < N; i++) {
    if(grad < vec[i]) cnt++;
    else max_len = max(max_len, cnt), cnt = 1;
    grad = vec[i];
  }
  max_len = max(max_len, cnt);
  cout << N - max_len << endl;
  return 0;
}
