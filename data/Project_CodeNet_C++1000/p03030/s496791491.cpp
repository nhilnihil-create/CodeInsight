#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  vector<tuple<string, int, int>> P(N);
  rep(i, N)
  {
    string a;
    int b;
    cin >> a >> b;
    P.at(i) = make_tuple(a, b * -1, i);
  }

  sort(P.begin(), P.end());
  //reverse(P.begin(), P.end());
  vector<int> d(N);
  rep(i, N)
  {
    string a;
    int b, c;
    tie(a, b, c) = P.at(i);
    //d.at(i) = c;
    cout << c + 1 << endl;
  }
}
