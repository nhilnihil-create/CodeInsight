#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x, i;
  cin >> N >> x;
  vector<int> a(N);
  for (i = 0; i < N; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  int id = 0;
  for (i = 0; i < N; i++) {
    if (x < a.at(i)) break;
    else if (i == N - 1 && x > a.at(i)) break;
    x -= a.at(i);
    id++;
  }
  
  cout << id << endl;
}
