#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,K;
  cin >> N >> K;
  
  int A;
  vector<int> cnt(N);
  for(int i=0; i<N; i++){
    cin >> A;
    cnt.at(A-1)++;
  }
  
  sort(cnt.begin(),cnt.end());
  
  int ans=0;
  for(int i=0; i<N-K; i++){
    ans += cnt.at(i);
  }
  
  cout << ans << endl;
  
}
