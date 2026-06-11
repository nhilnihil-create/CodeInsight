#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> s(N);
  for (int i = 0; i < N; i++){
    cin >> s[i];
  }
  int ans = 0;
  int A = 0;
  int B = 0;
  int diff = 0;
  for (int i = 0; i < N; i++){
    int K = s[i].size();
    for (int j = 0; j < K - 1; j++){
      if (s[i].substr(j, 2) == "AB"){
        ans++;
      }
    }
    if (s[i][0] == 'B'){
      B++;
      if (s[i][K - 1] == 'A'){
        A++;
      } else {
        diff++;
      }
    } else if (s[i][K - 1] == 'A'){
      A++;
      diff++;
    }
  }
  ans += min(A, B);
  if (diff == 0 && A != 0){
    ans--;
  }
  cout << ans << endl;
}