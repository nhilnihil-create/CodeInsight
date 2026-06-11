#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int N, M;

int main() {
  map<string, int> pscore;
  cin >> N;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    pscore[s]++;
  }
  cin >> M;
  string t;
  map<string, int> mscore;
  for (int i = 0; i < M; i++) {
    cin >> t;
    mscore[t]++;
  }
  int ans = 0;
  for (auto itr = pscore.begin(); itr != pscore.end(); itr++) {
    ans = max(ans, pscore[itr->first] - mscore[itr->first]);
  }
  cout << ans << endl;
  return 0;
}