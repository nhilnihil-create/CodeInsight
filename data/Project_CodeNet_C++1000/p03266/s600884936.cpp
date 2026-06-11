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


void modulo_summation()
{
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ans += a - 1;
  }

  cout << ans << "\n";
}


//skip
void all_green()
{
  int d, g;
  cin >> d >> g;
  vector<int> p(d);
  vector<int> c(d);
  for (int i = 0; i < d; ++i) cin >> p[i] >> c[i];


}


void base_2_number()
{
  int n;
  cin >> n;

  string s = "";
  if (n == 0) s = '0' + s;
  while (n != 0)
  {
    if (n % 2 != 0)
    {
      --n; //-２進数の整合性
      s = '1' + s;
    }
    else
    {
      s = '0' + s;
    }
    n /= -2;
  }

  cout << s << "\n";
}


void to_infinity()
{
  string s;
  long long int k;
  cin >> s >> k;

  char digit = '1';
  for (int i = 0; i < k; ++i)
  {
    if (s[i] != '1')
    {
      digit = s[i];
      break;
    }
  }
  cout << digit << "\n";
}


void candles()
{
  int n, k;
  cin >> n >> k;
  vector<long long int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  long long int ans = 100000000000000000;
  for (int i = 0; i < n - k + 1; ++i)
  {
    long long int tmp = abs(x[i + k - 1] - x[i])+ min(abs(x[i]), abs(x[i + k - 1]));
    ans = min(ans, tmp);
  }

  cout << ans << "\n";
}


void triangular_relationship()
{
  int n, k;
  cin >> n >> k;

  if (k % 2 != 0)
  {
    long long int a = n / k;
    cout << a * a * a << "\n";
  }
  else
  {
    long long int a = n / k;
    long long int b = 2 * n / k;
    cout << a * a * a + (b - a) * (b - a) * (b - a) << "\n";
  }
}


int main()
{
  //minimization();
  //linear_approximation();
  //modulo_summation();
  //all_green();
  //base_2_number();
  //to_infinity();
  //candles();
  triangular_relationship();
}
