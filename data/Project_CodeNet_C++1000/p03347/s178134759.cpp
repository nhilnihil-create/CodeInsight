#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main() {
  
  int N;
  cin >> N;

  vector<int> A(N);
  for(int i = 0;i < N;i++) cin >> A.at(i);

  if(A.at(0) != 0) {
    cout << -1 << endl;
    return 0;
  }

  long long ans = 0;
  for(int i = 0;i < N-1;i++) {
    if(A.at(i+1)-A.at(i) > 1) {
      cout << -1 << endl;
      return 0;
    }
    if(A.at(i) + 1 == A.at(i+1)) ans++;
    else ans += A.at(i+1);
  }

  cout << ans << endl;

}