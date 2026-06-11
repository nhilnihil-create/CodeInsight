#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  int a, b;
  cin >> a >> b;
  int diff = max(a, b) - min(a,b);
  if (diff > 1) {
    cout << ":(" << endl;
  } else {
    cout << "Yay!" << endl;
  }
  return 0;
}