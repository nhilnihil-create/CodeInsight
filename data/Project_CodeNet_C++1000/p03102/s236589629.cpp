#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M, C, a, temp, ans = 0;
  cin >> N >> M >> C;
  vector<int> B(M);
  for (int i = 0; i < M; i++){
    cin >> B[i];
  }
  for (int i = 0; i < N; i++){
    temp = 0;
    for (int j = 0; j < M; j++){
      cin >> a;
      temp += a * B[j];
    }
    temp += C;
    if (temp > 0){
      ans++;
    }
  }
  cout << ans;
}
  