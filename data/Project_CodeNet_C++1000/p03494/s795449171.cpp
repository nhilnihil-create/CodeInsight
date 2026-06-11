#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 100;
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    int cnt =0;
    while(a % 2 == 0){
      cnt++;
      a/=2;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}