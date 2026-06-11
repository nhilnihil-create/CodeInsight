#include<iostream>
#include<string>

using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  int w = n % 500;
  if ((n < a) || (w < a) || ((w == 0) && (a == 0))) {
      cout << "Yes" << endl;
  }
  else {
      cout << "No" << endl;
  }
}