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
  map<int,int> RD;
  set<int> s;
  for (int i = 0; i < M; i++) {
    int x;
    cin >> x;
    RD[x] += 1;
    s.insert(x);
  }
  
  for (int e : s) {
    if (RD[e] > MD[e]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
