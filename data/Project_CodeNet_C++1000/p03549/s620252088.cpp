#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M, E = 0;
  cin >> N >> M;
  int64_t t = 1900 * M + 100 * (N - M);
  cout << t * pow(2, M) << endl;
}