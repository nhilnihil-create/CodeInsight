#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, cs;
  cin >> A >> B >> cs;
  int ans = 0;
  if(A <= cs) {
    ans++;
  }
  if(cs <= A + B) {
    ans++;
  }
  if(ans == 2) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
