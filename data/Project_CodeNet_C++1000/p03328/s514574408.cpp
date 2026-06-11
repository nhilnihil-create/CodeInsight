#include<iostream>
using namespace std;
int main () {
  int a, b;
  cin >> a >> b;
  int dis = b - a;
  for (int i = dis; i >= 0; i --) {
    b -= i;
  }
  cout << -b << endl;
}