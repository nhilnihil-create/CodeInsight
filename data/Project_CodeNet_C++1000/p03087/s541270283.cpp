#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  int c = 0;
  vector<int> sum(N);
  sum[0] = 0;
  for (int i = 1; i < N; i++)
  {
    if (S[i - 1] == 'A' && S[i] == 'C')
    {
      c++;
    }
    sum[i] = c;
  }

  rep(i, Q)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;

    int c;
    if (l == 0)
      c = sum[r];
    else
    {
      c = sum[r] - sum[l];
    }
    cout << c << endl;
  }

  return 0;
}
