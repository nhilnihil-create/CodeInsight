#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }
  
  long long L0 = 2, L1 = 1, L;
  for(int i = 2; i <= n; ++i) {
    L = L0 + L1;
    L0 = L1;
    L1 = L;
  }

  cout << L << endl;
  return 0;
}