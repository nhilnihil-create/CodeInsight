#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define range(i, start, end) for (int i = (int)start; i < (int)(end); i++)

string operator*(string str, size_t n) {
  string result = "";
  rep(i, n){
  	result += str;
  }
  return result;
}


int main() {
  int a, b, cnt = 0;
  string s, rev;
  cin >> a >> b;
  range(i, a, b+1){
    s = to_string(i);
    rev = s;
    reverse(rev.begin(), rev.end());
    if (s == rev) {
      cnt += 1;
    }
  }
  cout << cnt << endl;
}