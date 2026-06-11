#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S == "abc"||
      S == "acb"||
      S == "bac"||
      S == "bca"||
      S == "cab"||
      S == "cba")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
