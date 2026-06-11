#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int A, B, K;
  cin >> A >> B >> K;
  int mod0cnt = 0;
  for (int i = min(A, B); i > 0; i--) {
    if ((A%i==0) && (B%i==0)) {
      mod0cnt++;
      if (mod0cnt==K) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
