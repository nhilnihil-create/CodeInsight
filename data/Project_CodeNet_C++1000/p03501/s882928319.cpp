#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  
  int p1, p2;
  p1 = a * n;
  p2 = b;
  
  if(p1 <= p2)
    cout << p1 << endl;
  if(p2 < p1)
    cout << p2 << endl;
}
