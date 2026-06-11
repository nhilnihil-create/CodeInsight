#include <iostream>
using namespace std;

int main() {
  char a[10], b[10];
  cin >> a >> b;
  if (a[0] == b[2] && a[1] == b[1] && a[2] == b[0]){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}