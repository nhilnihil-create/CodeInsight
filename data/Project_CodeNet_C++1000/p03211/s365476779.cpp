#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 753;
  int sub;
  int N = S.size();
  for(int i = 0; i < N - 2; i++) {
    int num = (S[i] - '0') * 100 + (S[i+1] - '0') * 10 + (S[i+2] - '0');
    if(num > 753) {
      sub = num - 753;
    }
    else {
      sub = 753 - num;
    }
    if(ans > sub) {
      ans = sub;
    }
  }
  cout << ans << endl;
}