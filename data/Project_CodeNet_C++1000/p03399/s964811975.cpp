#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  int sum = 0;
  int tmp1,tmp2;

  cin >> tmp1 >> tmp2;
  sum += min(tmp1,tmp2);
  cin >> tmp1 >> tmp2;
  sum += min(tmp1,tmp2);

  cout << sum << "\n";
}
