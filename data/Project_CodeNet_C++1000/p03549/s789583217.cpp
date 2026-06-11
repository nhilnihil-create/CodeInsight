#include <iostream>

using namespace std;

int main(void){
  int N, M;
  cin >> N >> M;
  // 入力終了

  int first_time = 1900*M + 100*(N-M);
  
  int p_inv = 1;
  for(int i=0; i<M; i++)
    p_inv = p_inv*2;
  
  cout << first_time*p_inv << endl;
  

  return 0;
}
