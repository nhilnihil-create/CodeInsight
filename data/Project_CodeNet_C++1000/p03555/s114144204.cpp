#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  int ans;
  cin >> A >> B;
  if(A.at(0) == B.at(2)) {
    ans++;
  }
  if(A.at(1) == B.at(1)) {
    ans++;
  }
  if(A.at(2) == B.at(0)) {
    ans++;
  }
  if(ans == 3) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}