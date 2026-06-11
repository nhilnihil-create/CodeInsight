#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<string, int>> rest1(N), rest2(N);
  for (int i = 0; i < N; i++)
    cin >> rest1.at(i).first >> rest1.at(i).second;
  for (int i = 0; i < N; i++)
    rest1.at(i).second *= -1;
  rest2 = rest1;
  sort(rest2.begin(), rest2.end());
  for (int i = 0; i < N; i++) {
    rest1.at(i).second *= -1;
    rest2.at(i).second *= -1;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (rest2.at(i) == rest1.at(j))
        cout << j + 1 << endl;
    }
  }
    
}