#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
  string s;

  cin >> s;

  int n = s.length();

  if(n == 2) {
    if(s[0] == s[1]) {
      cout <<"NO" << endl;
      return 0;
    }
  }
    if(n == 3) {
      if(s[0] == s[1] || s[0] == s[2] || s[1] == s[2]) {
	cout << "NO" << endl;
	return 0;
      }
    }
    int c[3] = {};

      for(int i = 0; i < n; i++) {
	c[s[i] - 'a']++;
      }

      int tmp = abs(c[0] - c[1]);
      int tmp2 = abs(c[1] - c[2]);
      int tmp3 = abs(c[2] - c[0]);
      
      if(tmp > 1 || tmp2 > 1 || tmp3 > 1) {
	cout << "NO" << endl;
	return 0;
      }

      cout << "YES" << endl;
}
