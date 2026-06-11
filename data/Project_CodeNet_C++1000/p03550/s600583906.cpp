#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n,w,z;

  cin >> n >> w >> z;

  if ( n == 1 ) {
    int tmp;
    scanf("%d", &tmp);

    cout << abs(tmp-z) << "\n";
  } else {
    int tmp1,tmp2;
    for ( int i = 0; i < n-2; ++i ) scanf("%d", &tmp1);
    scanf("%d%d", &tmp1, &tmp2);

    cout << ( abs(tmp2-z) > abs(tmp2-tmp1) ? abs(tmp2-z) : abs(tmp2-tmp1) )<< "\n";
  }
}
