#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int N;
  double X, sum = 0.0;
  cin >> N;
  string U;

  for (int i = 0; i < N; i++) {
    cin >> X >> U;
    if(U == "JPY"){
      sum += X;
    }else{
      sum += X * 380000.0;
    }
  }
  printf("%f\n", sum);
  return 0;
}
