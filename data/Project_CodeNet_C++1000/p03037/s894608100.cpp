#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  int max_L = 0, min_R = 100001;
  for(int i = 0;i < M;i++){
    int L, R;
    cin >> L >> R;
    
    max_L = max(max_L, L);
    min_R = min(min_R, R);
  }
  
  cout << max(0, min_R - max_L + 1) << endl;
  
  return 0;
}