#include <bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int a, b, ans = 0;
  cin >> a;
  for(int i = 0; i < N - 1; i++){
    cin >> b;
    if(a == b){
      ans++;
      b = -1;
    }
    a = b;
  }
  cout << ans << endl;
  return 0;
}