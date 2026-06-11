#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, asum = 0, bsum = 0, lim, acnt = 0, bcnt = 0;
  cin >> N;
  vector<int64_t> A(N), B(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    asum += A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> B.at(i);
    bsum += B.at(i);
  }
  lim = bsum - asum;
  for (int i = 0; i < N; i++)
  {
    if (A.at(i) > B.at(i))
    {
      bcnt += A.at(i) - B.at(i);
    }
    else if ((B.at(i) - A.at(i)) % 2 == 0)
    {
      acnt += (B.at(i) - A.at(i)) / 2;
    }
    else
    {
      acnt += (B.at(i) - A.at(i)) / 2 + 1;
      bcnt += 1;
    }
  }
  cout << (acnt >= bcnt ? "Yes" : "No") << endl;
}