 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ans = false;
  for(int a = 0; a <= 100; ++a){
    for(int b = 0; b <= 100; ++b){
      
      if(ans) break;
      int total = 4*a + 7*b;
      if(total == N) ans = true;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}