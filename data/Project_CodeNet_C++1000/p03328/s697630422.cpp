#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  int c = b - a;
  c = c * (c + 1) / 2;
  cout << c - b << endl;
}
