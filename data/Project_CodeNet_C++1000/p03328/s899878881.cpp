#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b; cin >> a >> b;
  int dff = b - a;
  cout << (1+dff)*dff/2 - b << endl;
}