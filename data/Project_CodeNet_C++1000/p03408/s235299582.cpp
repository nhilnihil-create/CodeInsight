#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> blue(N);
  for (int i = 0; i < N; i++) {
    string b;
    cin >> b;
    blue.at(i) = b;
  }
  
  int M;
  cin >> M;
  vector<string> red(M);
  for (int i = 0; i < M; i++) {
    string r;
    cin >> r;
    red.at(i) = r;
  }
  
  map<string, int> m;
  
  for (string x : blue) { 
    if (m.count(x)) m.at(x) += 1;
    else m[x] = 1;
  }
  
  for (string x : red) { 
    if (m.count(x)) m.at(x)--;
    else m[x] = -1;
  }

  int count = 0; 
  int max = 0;
  for (auto p : m) {
    count = p.second;
    if (count > max) max = count;
  }
  cout << max << endl;
}