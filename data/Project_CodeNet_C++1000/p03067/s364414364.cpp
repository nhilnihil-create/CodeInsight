#include<iostream>
using namespace std;
void swap(int& a, int& b) {
  int t = a;
  a = b;
  b = t;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a ,b);
  cout << (a < c && c < b ? "Yes" : "No") << endl;
}
