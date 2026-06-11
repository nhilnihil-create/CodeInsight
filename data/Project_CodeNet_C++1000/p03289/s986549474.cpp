#include <iostream>

using namespace std;

bool isLow(char c) { return 'a' <= c && c <= 'z'; }

int main() {
  string s;
  cin >> s;
  bool available = s[0] == 'A' && isLow(s[1]) && isLow(s[s.size() - 1]);
  int cnt = 0;
  for (int i = 2; i < s.size() - 1; ++i) if (s[i] == 'C') cnt++; else if (!isLow(s[i])) available = 0;
  if (cnt != 1) available = 0;
  puts(available ? "AC" : "WA");
}
