#include <bits/stdc++.h>
using namespace std;

int ctoi(char c) {
	switch (c) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		default: return 0;
	}
}

int main() {
  string s;
  cin >> s;
  int ans = 100000000;
  int K = s.size();
  for (int i = 0; i <= K - 3; i++) {
    int a = ctoi(s.at(i));
    int b = ctoi(s.at(i + 1));
    int c = ctoi(s.at(i + 2));
    ans = min(ans, abs(a * 100 + b * 10 + c - 753));
  }
  cout << ans << endl;
}