#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;
const int mod = 1000000007;
int n;

int check(vector<int> &A)
{
  rep(i, n)
  {
    if (A.at(i) % 2 != 0)
    {
      return 0;
    }
  }
  return 1;
}

void sla(vector<int> &A)
{
  rep(i, n)
  {
    A.at(i) /= 2;
  }
}

int main()
{
  cin >> n;
  vector<int> A(n);
  rep(i, n)
  {
    int a;
    cin >> a;
    if (a % 2 != 0)
    {
      cout << 0 << endl;
      exit(0);
    }
    A.at(i) = a;
  }
  int cnt = 0;
  do
  {
    sla(A);
    cnt++;
  } while (check(A) == 1);
  cout << cnt << endl;
}
