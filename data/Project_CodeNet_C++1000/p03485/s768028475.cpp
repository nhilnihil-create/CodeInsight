#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,average,r;
  cin >> a >> b;
  r = (a+b) % 2;
  if (r == 1)
    average = (a + b) / 2 + 1;
  else
    average = (a + b) / 2;
  cout << average << endl;
  return 0;
}