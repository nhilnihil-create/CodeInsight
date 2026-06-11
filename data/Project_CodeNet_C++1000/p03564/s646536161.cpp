#include <iostream>
using namespace std;

int main() {
  int N,K,T=1;
  cin >> N >> K;
  while(N--){
    if((T+K) > (T*2))
      T *= 2;
    else
      T += K;
  }
  cout << T << endl;
}
