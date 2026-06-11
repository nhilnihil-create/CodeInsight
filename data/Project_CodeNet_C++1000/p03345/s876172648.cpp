#include <iostream>
#include <cmath>

using namespace std;

int main(){
  long long A, B, C, K;
  cin >> A >> B >> C >> K;

  if(abs(A-B) > 1000000000000000000){
    printf("Unfair\n");
  }else if(K%2 == 0){
    printf("%lld\n", A - B);
  }else{
    printf("%lld\n", B - A);
  }
}
