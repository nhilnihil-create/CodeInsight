#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p.at(i);
  }
  sort(p.begin(), p.end()); 
  reverse(p.begin(), p.end());
  int answer;
  answer = 0;
  for (int j = 1; j < N; j++) {
    answer+= p.at(j);
  }
  cout << answer + (p.at(0) / 2) << endl;
}
 
