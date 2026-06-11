#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int n;
  cin >> n;
  
  for (int i=1; i<=32767; i++) {
    if (i*i <= n && n < (i+1)*(i+1)) cout << i*i << endl;
  }
}