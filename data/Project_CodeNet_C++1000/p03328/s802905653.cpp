#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int sa = (b - a) * (b - a + 1) / 2;
  cout << abs(b - sa) << endl;
}