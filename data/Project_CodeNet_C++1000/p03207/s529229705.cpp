#include <iostream>
using namespace std;

int main()
{
  int n, max_val = 0, res = 0;
  cin >> n;
  for(int i=0; i<n; i++)
  {
    int p;
    cin >> p;
    res += p;
    max_val = max(max_val, p);
  }
  
  res -= max_val / 2;
  cout << res << endl;
  return 0;
}