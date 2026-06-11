#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int h = 0;
  
  for (int i=0; i < b-a; i++){
    h += i;
  }
  cout << h-a<< endl;
}