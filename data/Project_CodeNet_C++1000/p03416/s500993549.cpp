#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B, cnt = 0;
  cin >> A >> B;
  string S, S2;
  for (int i = A; i <= B; i++){
    S = to_string(i);
    S2 = S;
    reverse(S2.begin(), S2.end());
    if(S == S2) cnt++;
  }
  cout << cnt << endl;
  return 0;
}