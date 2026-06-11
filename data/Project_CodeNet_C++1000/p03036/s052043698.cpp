#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,d,x,f;
  cin >> r >> d >>x;
	f = x;
  for (int i = 0; i < 10; i++)
  {
    f = r*f - d;
    cout << f << endl;
  }
  

}