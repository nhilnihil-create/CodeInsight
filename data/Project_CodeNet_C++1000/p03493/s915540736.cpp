#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  cin >> str;
  int count = 0;
  for (int i=0; i<=2; i++) {
    if (str[i] == '1') {
      count++;
    }
  }
  cout << count << endl;
}