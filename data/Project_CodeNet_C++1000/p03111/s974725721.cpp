#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int A, B, C;

int calc_score(vector<int> a, int num)
{
  int score = 0;
  int aa = 0;

  if (a.size() == 0)
  {
    // invalid
    return 10000;
  }

  aa += a[0];
  for (int i = 1; i < a.size(); i++)
  {
    aa += a[i];
    score += 10;
  }

  score += std::abs(aa - num);

  return score;
}

int dfs(vector<int> a, vector<int> b, vector<int> c, vector<int> l, int pos)
{
  if (pos == l.size())
  {
    // calculate the score
    int score = 0;
    score += calc_score(a, A);
    score += calc_score(b, B);
    score += calc_score(c, C);

    return score;
  }

  vector<int> a2 = a;
  a2.emplace_back(l[pos]);
  vector<int> b2 = b;
  b2.emplace_back(l[pos]);
  vector<int> c2 = c;
  c2.emplace_back(l[pos]);

  int num = dfs(a2, b, c, l, pos + 1);
  num = std::min(dfs(a, b2, c, l, pos + 1), num);
  num = std::min(dfs(a, b, c2, l, pos + 1), num);
  num = std::min(dfs(a, b, c, l, pos + 1), num);

  return num;
}

int main()
{
  int N;
  cin >> N >> A >> B >> C;

  vector<int> l(N);
  rep(i, N)
  {
    cin >> l[i];
  }

  vector<int> a, b, c;
  int pos = 0;
  int num = dfs(a, b, c, l, pos);

  cout << num << endl;

  return 0;
}
