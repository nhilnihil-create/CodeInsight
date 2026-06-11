#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,ans = 0;
  cin >> N;
  vector<int>vec(N);
  for(int i=0; i<N; i++){
    cin >> vec[i];
    ans += vec[i];
  }
  sort(vec.begin(),vec.end());
  ans -= vec[N-1]/2;
  cout << ans << endl;
}
