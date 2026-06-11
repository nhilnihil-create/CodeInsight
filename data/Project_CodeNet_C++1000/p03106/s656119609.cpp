#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int A, B, K;
  cin >> A >> B >> K;
  
  int cnt = 0;
  for(int i = min(A, B);i > 0 ;i--){
    if(A % i + B % i == 0) cnt++;
    if(cnt == K){
      cout << i << endl;
      return 0;
    }
  }
  
  return 0;
}