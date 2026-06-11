#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long a=2, b=1;
  long long ans = 2;
  
  cin >> N;
  if (N==0) cout << 2 << endl;
  else if (N==1) cout << 1 << endl;
  else{
  for (int i = 0;i < N-1; i++){
    ans = a + b;
    a = b;
    b = ans;
    }
  cout << ans << endl;
  }
}
