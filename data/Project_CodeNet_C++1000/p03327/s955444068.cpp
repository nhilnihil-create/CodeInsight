#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int N;
  cin >> N;
  string A="ABC";
  if (N>999) {
    //N-=999;
    A="ABD";
  }
  cout << A << endl;
}
