#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t Li,Li_1,Li_2;
  int N;
  Li_1 = 1;
  Li_2 = 2;
  Li = Li_1;
  
  cin >> N;
  
  if(N > 1){
  	for(int i = 1; i < N; i++){
      Li = Li_1 + Li_2;
      Li_2 = Li_1;
      Li_1 = Li;
    }
  }
  
  cout << Li << endl;
  return 0;
}
