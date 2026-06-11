#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
  long long int N, A, B;
  cin >> N >> A >> B;
  if((A + B - 1 > N) || (A*B < N)){
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans(N,0);
  for(int i = 0; i*B < N; ++i){
    for(int j = 0; j < B; ++j){
      if(i*B + j >= N) break;
      ans[i*B + j] = min((i + 1)*B, N) - j;
    }
  }
  int ok = -1, ng = N;
  while(ng - ok > 1){
    int m = (ok + ng)/2;
    if((m + B - 1)/B + N - m > A) ok = m;
    else ng = m;
  }
  sort(ans.begin() + ok, ans.end());
  for(int i = 0; i < N - 1; ++i) cout << ans[i] << " ";
  cout << ans.back() << endl;
  return 0;
}
