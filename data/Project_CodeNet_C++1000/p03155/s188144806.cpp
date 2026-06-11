#include <iostream>
using namespace std;

int main() {
  int N, H, M;cin >>N >> H >> M;
  int a = N - H + 1, b = N - M + 1;
  cout << a * b << endl;
}