#include <iostream>
using namespace std;
int main() {
  int N; cin >> N;
  if(N == 3) {
    cout << "2 5 63" << endl;
  } else {
    if(N & 1) {
      int a[8] = {6, 2, 10, 3, 9, 4, 8, 12};
      for(int i = 0; i < N; ++i) {
        cout << a[i % 8] + i / 8 * 12 << endl;
      }
    } else {
      int a[8] = {2, 10, 3, 9, 4, 8, 6, 12};
      for(int i = 0; i < N; ++i) {
        cout << a[i % 8] + i / 8 * 12 << endl;
      }
    }
  }
}