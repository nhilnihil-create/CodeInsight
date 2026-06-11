#include <bits/stdc++.h>
using namespace std;

int main()
{
  string S;
  cin >> S;
  vector<string> A = {"KIH", "B", "R"};
  queue<string> Q;
  Q.push("");
  Q.push("A");
  for (int i = 0; i < A.size(); i++)
  {
    int64_t sq = Q.size();
    for (size_t j = 0; j < sq; j++)
    {
      string qf = Q.front();
      Q.pop();
      string nx = qf.append(A.at(i));
      Q.emplace(nx);
      Q.emplace(nx.append("A"));
    }
  }
  while (!Q.empty())
  {
    if (S == Q.front())
    {
      cout << "YES" << endl;
      return 0;
    }
    Q.pop();
  }
  cout << "NO" << endl;
}