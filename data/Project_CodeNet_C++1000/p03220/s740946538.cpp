#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int N,T,A;
  cin >> N >> T >> A;
  vector<int> H(N);
  for(int i = 0; i < N; i++){
    cin >> H.at(i);
  }
  int ans = 0;
  float min_dif = abs(A - (T - H.at(0) * 0.006));
  for(int i = 1; i < N; i++){
    float dif = abs(A - (T - H.at(i) * 0.006));
    if(dif < min_dif){
      min_dif = dif;
      ans = i;
    }
  }
  cout << ans + 1;
  return 0;
}