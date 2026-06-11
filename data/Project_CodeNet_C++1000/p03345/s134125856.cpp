#include <iostream>
using namespace std;
int main() {
  int A, B, C;
  long long K;
  cin >> A >> B >> C >> K;
  cout << (A - B) * (K % 2 ? -1 : 1) << endl;
}
