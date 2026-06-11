#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  int x=b-a,y=0;
  for(int i=1; i<=x; i++) {
    y += i;
  }
  cout << y-b << endl;
}