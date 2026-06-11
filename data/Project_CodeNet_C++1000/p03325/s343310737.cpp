#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for(int i=0; i<N; i++){
    long long A;
    cin >> A;
    for(int i=0; i>-1; i++){
      if(A%2 == 0 && A != 0){
        ans++;
        A /= 2;
      }
      else{
        break;
      }
    }
  }
  cout << ans << endl;
}
