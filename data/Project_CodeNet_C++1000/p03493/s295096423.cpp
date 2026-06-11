#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int count = 0;
  string str;
  cin >> str;
  rep(i,3) {
  	if (str.at(i)=='1') {
      count += 1;
    }
  }
  cout << count << endl;
}