#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<int> p(N);
  int sum = 0;

  for (int i = 0; i < N; i++)
  {
    cin >> p.at(i);
    sum += p.at(i);
  }

  int maxElement = *max_element(p.begin(), p.end());

  cout << sum - maxElement / 2 << endl;
}
