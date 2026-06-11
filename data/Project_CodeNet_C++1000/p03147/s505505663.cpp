#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>vec(N+1);
  for(int i=0; i<N; i++){
    cin >> vec[i];
  }
  vec[N] = 0;
  int ans =0;
  for(int i=1; i < N+1; i++){
    if(vec[i] < vec[i-1]){
      ans += vec[i-1] - vec[i];
    }
  }
  cout << ans << endl;
}
