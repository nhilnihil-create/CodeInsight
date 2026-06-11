#include<bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  string ans;
  if(A > 8 || B > 8) {
    ans = ":(";
  } else {
  	ans = "Yay!";
  }
  cout << ans << endl;
}