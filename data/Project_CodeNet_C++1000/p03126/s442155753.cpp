#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  vector<int>vec(M,0);
  for(int i=0; i<N; i++){
    int K;
    cin >> K;
    for(int i=0; i<K; i++){
      int A;
      cin >> A;
      vec[A-1] += 1;
    }
  }
  int ans=0;
  for(int i=0; i<M; i++){
    if(vec[i] == N){
      ans++;
    }
  }
  cout << ans << endl;
}
