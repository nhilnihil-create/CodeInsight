#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int> > mat;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int>::iterator lb = lower_bound(a.begin(), a.end(), a[n - 1] / 2);
  vector<int>::iterator sub = lb - 1;
  cout << a[n - 1] << " ";
  cout << (abs(2 * *lb - a[n - 1]) < abs(2 * *sub - a[n - 1]) ? *lb : *sub) << "\n";
}