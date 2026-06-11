#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin >> N;

  vector<pair<pair<string, int>, int>> v(N);
  for (int i = 0; i < N; i++)
  {
    string a;
    int b, c = i + 1;
    cin >> a >> b;
    v.at(i) = make_pair(make_pair(a, -b), c);
  }

  sort(v.begin(), v.end());

  for (auto i : v)
  {
    cout << i.second << endl;
  }
}