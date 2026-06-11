#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<char> word(N);
  vector<int> wtotal(N);
  vector<int> count(N);
  for (int i = 0; i < N; i++) {
    cin >> word.at(i);
  }
  int total = 0;
  for (int i = 0; i < N; i++) {
    if (word.at(i) == 'W') {
      total++;
    }
    wtotal.at(i) = total;
  }
  for (int i = 1; i < N; i++) {
    count.at(i) += wtotal.at(i - 1);
    count.at(i) += (N - 1 - i) - (wtotal.at(N - 1) - wtotal.at(i));
  }
  count.at(0) = (N - 1) - (wtotal.at(N - 1) - wtotal.at(0));
  sort(count.begin(), count.end());
  cout << count.at(0) <<endl;
  return 0;
}