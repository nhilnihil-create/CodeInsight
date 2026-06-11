#include <iostream>
#include <string>
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.size();

  for(int i = 0; i < (1<<(n-1)); i++) {
    string str = ""; str.push_back(s[0]);
    int sum = s[0] - '0';
    for(int j = 0; j < n-1; j++) {
      if((i>>j) & 1) {
        sum += s[j+1] - '0';
        str.push_back('+');
        str.push_back(s[j+1]);
      } else {
        sum -= s[j+1] - '0';
        str.push_back('-');
        str.push_back(s[j+1]);
      }
    }
    if(sum == 7) {
      cout << str << "=7" << endl;
      return 0;
    }
  }

  return 0;
}
