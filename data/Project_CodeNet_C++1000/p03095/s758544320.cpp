#include <iostream>

using namespace std;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
using ld = long double;

int const sigma = 26;
int const modulo = 1000000007;
int frec[1 + sigma];

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i < s.size(); i++)
    frec[s[i] - 'a']++;
  int result = 1;
  for(int i = 0; i < sigma; i++)
    result = 1LL * result * (frec[i] + 1) % modulo;
  cout << result - 1;
  return 0;
}
