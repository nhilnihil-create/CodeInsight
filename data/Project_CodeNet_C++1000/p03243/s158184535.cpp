#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int N, a;
  cin >> N;

  for(int i = 0; i< 10; i++){
    a = i * 100 + i * 10 + i;
    if(N <= a){
      cout << a << endl;
      break;
    }
  }
  return 0;
}
