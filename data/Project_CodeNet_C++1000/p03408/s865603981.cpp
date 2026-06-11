#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];  
  }

  int M;
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];  
  }
  
  int m = 0;
  for (auto i = s.begin(); i != s.end(); i++) {
  	int profit = 0;
  	for (auto j = s.begin(); j != s.end(); j++) {
      if (*i == *j)
        profit++;
  	}
  	for (auto j = t.begin(); j != t.end(); j++) {
      if (*i == *j)
        profit--;
  	}
    if (profit > m)
      m = profit;
  }
  cout << m << endl;
}
