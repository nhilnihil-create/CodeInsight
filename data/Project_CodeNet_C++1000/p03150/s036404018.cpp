#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const long long INF = 1LL << 60;
const long long P = 1000000007;

int main() {
  string s;
  cin >> s;
  string t = "keyence";
  bool flag = false;
  for(int i = 0; i < s.size(); i++) {
    for(int j = i; j < s.size(); j++) {
      string u = "";
      for(int k = 0; k < s.size(); k++) {
        if(i > k || k > j) {
          u.push_back(s[k]);
        }
      }
      if(u == t) {
        flag = true;
      }
    }
  }
  if(s == t) {
    flag = true;
  }
  if(flag) {
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
  return 0;
}