#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  int x = n - (n / 500) * 500;
  if (x < a || x == a){
    cout << "Yes" << endl;
  }
  if (x > a){
    cout << "No" << endl;
  }
}