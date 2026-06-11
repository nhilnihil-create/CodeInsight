#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  cout << (100*N+1800*M)*(1<<M) << endl;
}
