#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


void minimization()
{
  int n, k;
  cin >> n >> k;

  cout << ceil((float)(n - 1) / (float)(k - 1)) << "\n";
}


void linear_approximation()
{
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
  {
    int a;
    cin >> a;
    b[i] = a - (i + 1);
  }

  sort(b.begin(), b.end());

  int mid = b[n / 2];
  long long int ans = 0;
  for (int i = 0; i < n; ++i) ans += abs(mid - b[i]);
  cout << ans << "\n";

}


int main()
{
  //minimization();
  linear_approximation();
}
