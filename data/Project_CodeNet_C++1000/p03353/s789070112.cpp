#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int l = s.length();
  set<string> a;
  for (char c = 'a'; c <= 'z'; c++) {
    for (int i = 0; i < l; i++) {
      if (s[i] == c) {
        string t;
        for (int j = i; j < l; j++) {
          t += s[j];
          a.insert(t);
          if (j - i + 1 >= k) break; 
        }
      }
    }
    if (a.size() >= k) break;
  }
  auto itr = a.begin();
  /*for (int i = 0; i < a.size(); i++) {
    cout << *itr << endl;
    itr++;
  } */ 
  for (int i = 0; i < k - 1; i++) itr++;
  cout << *itr << endl;
}