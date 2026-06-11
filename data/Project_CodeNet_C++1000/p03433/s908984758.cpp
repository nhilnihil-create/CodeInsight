#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a;
  cin >> n >> a;
  if (n%500<=a) {
    cout << "Yes" << endl;
  }
  if (n%500>a) {
    cout << "No" << endl;
  }
}
