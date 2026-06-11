#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0;
  cin >> N;
  int count = 1;
  vector<tuple<string, int, int>> SP;
  
  for (int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    SP.push_back(make_tuple(s, 100 - p, count));
    count++;
  }
  
  sort(SP.begin(), SP.end());
  for (auto t : SP) {
  	cout << get<2>(t) << endl;
  }
}
