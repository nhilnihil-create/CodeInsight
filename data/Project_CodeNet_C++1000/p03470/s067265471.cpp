#include <bits/stdc++.h>
using namespace std;

// バケット法のmap ver.

int main() {
  int N;
  cin >> N;
  
  map<int, bool> table;
  int key;
  for (int i = 0; i < N; i++) {
    cin >> key;
    table[key] = 1;
  }
  
  cout << table.size() << endl;
}
