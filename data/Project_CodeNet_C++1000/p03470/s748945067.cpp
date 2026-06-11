#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> mochi(N);

  for (int i = 0; i < N; i++) {
    cin >> mochi.at(i);
  }
  
  sort(mochi.begin(),mochi.end());
  
  int x = 0, num = 0;

  for (int i = 0; i < N; i++) {
    if (mochi.at(i) != x) {
      x = mochi.at(i);
      num++;
    }
  }
  cout << num << endl;
}