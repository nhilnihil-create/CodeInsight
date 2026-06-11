#include <iostream>
using namespace std;
int main () {
  int N, A;
  cin >> N >> A;
  int R = N % 500;
  if (R == 0 || R <= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
