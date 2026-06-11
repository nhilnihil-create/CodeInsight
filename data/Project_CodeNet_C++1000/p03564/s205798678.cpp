#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k, sum = 1;
  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    int buf1 = sum * 2;
    int buf2 = sum + k;

    sum = min(buf1, buf2);
  }
  cout << sum << endl;
}
