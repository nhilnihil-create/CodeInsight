#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  map<int,int> MD;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    MD[x] += 1;
  }
  
  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    MD[x] -= 1;
  }
  
  for (auto m : MD) {
    if (MD[m.first] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
