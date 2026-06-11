#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long l[N+1];
  l[0] = 2;
  l[1] = 1;

  for (int i = 2; i < N+1; i++){
    l[i] = l[i-1] + l[i-2];
  }
   
  printf("%lld\n", l[N]);
}
