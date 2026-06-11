#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<pair<pair<string, int>, int>> rest(n);
  for (int i = 0; i < n; i++)
  {
    string a;
    int b;
    cin >> a >> b;
    rest[i].first.first = a;
    rest[i].first.second = -b;
    rest[i].second = i;
  }

  sort(rest.begin(), rest.end());
  for (int i = 0; i < n; i++)
  {
    cout << rest[i].second + 1 << endl;
  }
}
