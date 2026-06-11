#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
int const nmax = 26;
int frec[1 + nmax];

int main() {
  std::string s;
  std::cin >> s;
  if(s == "zyxwvutsrqponmlkjihgfedcba")
    std::cout << -1;
  else if(s.size() < 26) {
    for(char ch = 'a'; ch <= 'z'; ch++) {
      int result = 0;
      for(int j = 0;j < s.size(); j++)
        result |= (s[j] == ch);
      if(result == 0) {
        std::cout << s + ch;
        return 0;
      }
    }
  } else {
    for(int i = s.size() - 1; 0 < i; i--)
      if(s[i - 1] < s[i]) {
        std::string s2;
        for(int j = 0; j < i - 1; j++)
          s2 = s2 + s[j];
        for(int j = i - 1; j < s.size(); j++)
          frec[s[j] - 'a']++;
        for(int j = s[i - 1] - 'a' + 1; j < nmax; j++) 
          if(0 < frec[j]) {
            s2 += j + 'a';
            frec[j] = 0;
            break;
          }
        std::cout << s2 << '\n';
        return 0;
      }
  }
  return 0;
}
