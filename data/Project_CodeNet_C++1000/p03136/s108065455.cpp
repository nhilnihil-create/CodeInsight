#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> L(N);
  int max = 0;
  int sum = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> L.at(i);

    sum += L.at(i);

    if (L.at(i) > max)
      max = L.at(i);
  }

  cout << (sum - max > max ? "Yes" : "No") << endl;
}
