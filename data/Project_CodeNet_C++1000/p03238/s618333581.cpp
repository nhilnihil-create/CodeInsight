#include <iostream>
using namespace std;
int main() {
  int N; cin >> N;
  if (N == 1) printf("%s\n", "Hello World");
  else {
    int A, B; cin >> A >> B;
    printf("%d\n", A + B);
  }
}