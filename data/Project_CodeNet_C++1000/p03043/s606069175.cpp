#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  double N, K;
  cin >> N >> K;
  
  double ans = 0.0;
  for(int i = 0;i < N;i++){
    double score = i + 1;
    double prob = 1 / N;
    while(score < K){
      prob /= 2;
      score *= 2;
    }
    ans += prob;
  }
  
  cout << fixed << setprecision(10);
  cout << ans << endl;
  
  return 0;
}