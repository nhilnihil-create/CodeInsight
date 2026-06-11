#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  vector<int> d(109);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> d.at(i);
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  cout << d.size() - 1 << endl;
}
