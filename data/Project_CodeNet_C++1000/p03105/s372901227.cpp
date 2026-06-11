#include <iostream>
#include <string>
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = 0;
  rep(i, 0, c) {
    if(a <= b) {
      sum++;
      b -= a;
    }
  }
  cout << sum << "\n";
}
