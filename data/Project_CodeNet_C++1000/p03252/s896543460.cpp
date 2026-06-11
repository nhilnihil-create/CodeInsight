#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S, T;
  cin >> S >> T;
  int N = S.size();
  vector<int> A(26, 0), B(26, 0), v1(N), v2(N);
  int n = 1, m = 1;
  for (int i = 0; i < N; i++)
  {
    int a = S.at(i) - 'a';
    int b = T.at(i) - 'a';
    if (A.at(a))
    {
      v1.at(i) = A.at(a);
    }
    else
    {
      v1.at(i) = A.at(a) = n;
      n++;
    }
    if (B.at(b))
    {
      v2.at(i) = B.at(b);
    }
    else
    {
      v2.at(i) = B.at(b) = m;
      m++;
    }
    if (v1.at(i) != v2.at(i))
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}