#include<iostream>
#include<string>

using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  int w = n % 500;
  if ((w == 0) || (n < a) || ((w == 0) && (a == 0)) || (w < a)) {
      cout << "Yes" << endl;
  }
  else {
      cout << "No" << endl;
  }
}