#include <bits/stdc++.h>
using namespace std;

int main() {
  int s; cin >> s;
  
  vector<int> ai;
  ai.push_back(s);
  while (true) {
    int n = ai.back();
    int nn = 0;
    if (n%2 == 0) nn = n/2;
    else nn = 3*n+1;
    if (find(ai.begin(), ai.end(), nn) != ai.end()) {
      cout << ai.size()+1 << endl;
      break;
    } else ai.push_back(nn);
  }
}