#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  vector<int> k(M);
  vector<vector<int>> s(M);
  for (int i =0; i<M; i++) {
    cin >> k.at(i);
    for (int j =0; j<k.at(i); j++) {
      int a; cin >> a;
      s.at(i).push_back(a);
    }
  }
  vector<int> p(M);
  for (int i =0; i<M; i++) cin >> p.at(i);
  
  int count =0;
  for (int tmp =0; tmp< (1 << N); tmp++) {
    bitset<10> bit(tmp);
    int countK =0;
    for (int i =0; i<M; i++) {
      int countSwitch =0;
      int S = k.at(i);
      for (int j =0; j<S; j++) {
        if (bit[s.at(i).at(j)-1] == 1) countSwitch++;
      }
      if (countSwitch % 2 == p.at(i)) countK++;
    }
    if (countK == M) count++;
  } 
  cout << count << endl;  
}
  
  