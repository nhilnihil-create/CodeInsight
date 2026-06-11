#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  if(n == 1) cout << "Hello World\n";
  else {
    int a, b;
    cin >> a >> b;
    cout << a + b << "\n";
  }
}