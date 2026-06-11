#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M, C;
  cin >> N >> M >> C;
  
  vector<int> B(M);
  for(int i = 0;i < M;i++) cin >> B.at(i);
  
  int ans = 0;
  for(int i = 0;i < N;i++){
    int sum = C;
    for(int j = 0;j < M;j++){
      int A;
      cin >> A;
      
      sum += A * B.at(j);
    }
    
    if(sum > 0) ans++;
  }
  
  cout << ans << endl;
  
  return 0;
}