#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int lu(vector<int> &l, int N)
{
  if (N - 2 == 0)
  {
    return 0;
  }
  int sum = l.at(N - 1) + l.at(N - 2);
  return sum + lu(l, N - 1);
}

int main()
{
  int N;
  cin >> N;
  vector<int64_t> l(N + 1);
  l.at(0) = 2;
  l.at(1) = 1;
  //cout << lu(l, N) << endl;
  for (int i = 2; i <= N; i++)
  {
    l.at(i) = l.at(i - 1) + l.at(i - 2);
  }
  cout << l.at(N) << endl;
}
