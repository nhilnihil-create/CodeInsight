#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M, K;
  
  cin >> N >> M;
  
  vector<int> cnt(M);
  for(int i = 0;i < N;i++){
    cin >> K;
    for(int j = 0;j < K;j++){
      int a;
      cin >> a;
      cnt.at(a-1)++;
    }
  }
  
  int ans = 0;
  for(int i = 0;i < cnt.size();i++) if(cnt.at(i) == N) ans++;
  
  cout << ans << endl;
  
  return 0;
}