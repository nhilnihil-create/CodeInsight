#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<tuple<string, int, int>> r(N);
  for (int i = 0; i < N; i++) {
    string s;
    int p;
    cin >> s >> p;
    r.at(i) = make_tuple(s, p * (-1), i+1);
  }
 
  sort(r.begin(), r.end());
  
  for (int i = 0; i < N; i++) {
    int a, p;
    string s;
    tie(s, p, a) = r.at(i);  
    cout << a << endl;
  }
}