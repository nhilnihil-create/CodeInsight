#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a*b-((a*b)/2)*2 == 0) {
    cout << "Even" << endl;
  }
  else {
    cout << "Odd" << endl;
  }
}