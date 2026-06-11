#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  string s; cin >> s;
  int k = s.size();
  int won = 0;
  for(int i = 0; i < k; i++) {
    won += s[i] == 'o';
  }
  if(won + 15 - k >= 8) {
    puts("YES");
  }
  else {
    puts("NO");
  }
}