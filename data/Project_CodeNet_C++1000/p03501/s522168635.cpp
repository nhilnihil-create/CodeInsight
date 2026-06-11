#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
    cin >> a >> b >> c;
  int Plan1;
  int Plan2;
  	Plan1 = a * b;
    Plan2 = c;
  if (Plan1 >= Plan2){
    cout << Plan2 << endl;
  }
  else if (Plan1 < Plan2){
    cout << Plan1 << endl;
  }
}
