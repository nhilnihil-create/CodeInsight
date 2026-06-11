#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  long X;
  cin >> N >> X;
  vector<int> M(N);
  long sum = 0;
  for (int i=0; i<N; i++){
    cin >> M[i];
    sum += M[i];
  }
  sort(M.begin(), M.end());
  int ans = N;
  ans += (X-sum)/M[0];
  cout << ans;
  return 0;
}