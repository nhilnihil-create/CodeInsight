#include <bits/stdc++.h>
using namespace std;
string S;
int64_t K;

int main()
{
  cin >> S >> K;
  vector<string> st(0);
  for (int i = 0; i < S.size(); i++)
  {
    string s = S.substr(i, S.size() - i);
    st.push_back(s);
  }
  sort(st.begin(), st.end());
  set<string> used;
  for (int i = 0; i < st.size(); i++)
  {
    for (int j = 0; j < st.at(i).size(); j++)
    {
      string subs = st.at(i).substr(0, j + 1);
      used.insert(subs);
      if (used.size() == K)
      {
        cout << st.at(i).substr(0, j + 1) << endl;
        return 0;
      }
    }
  }
}
