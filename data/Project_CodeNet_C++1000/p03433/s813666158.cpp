#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  string reply;

  cin >> n >> a;

  n %= 500;

  if (n <= a) {
    reply = "Yes";
  } else {
    reply = "No";
  }
  cout << reply << endl;
}
