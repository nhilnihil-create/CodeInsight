#include <bits/stdc++.h>
using namespace std;
using sii = tuple<string, int, int>;

int main() {
  int N;
  cin >> N;
  vector<sii> list(N);
  for (int i = 0; i < N; i++){
    string s;
    int p;
    cin >> s >> p;
    list.at(i) = sii(s, -p, i + 1);
  }
  sort(list.begin(), list.end());
  for (int i = 0; i < N; i++){
    int no;
    tie(ignore, ignore, no) = list.at(i);
    cout << no << endl;;
  }
    
}