#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B;
  cin >> N >> A >> B;
  int x = N * A;
  int y = B;
  if (x > y){
  	cout << y << endl;
  }
  else if (x < y){
  	cout << x << endl;
  }
  else {
  	cout << y << endl;
  }
}
