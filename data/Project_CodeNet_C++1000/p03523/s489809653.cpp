#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  vector<string> t = {"KIHBR", "KIHBRA", "KIHBAR", "KIHBARA", 
                      "KIHABR", "KIHABRA", "KIHABAR", "KIHABARA", 
                      "AKIHBR", "AKIHBRA", "AKIHBAR", "AKIHBARA", 
                      "AKIHABR", "AKIHABRA", "AKIHABAR", "AKIHABARA"};
  bool flag = false;
  for (int i = 0; i < 16; i++) {
    if (s == t.at(i)) flag = true;
  }
  
  if (flag) cout << "YES\n";
  else cout << "NO\n";
}