#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a;
  set<int> st;
  for (int i = 0; i < 3; i++)
  {
    cin >> a;
    if (st.count(a))
      st.erase(a);
    else
      st.insert(a);
  }
  for (auto s : st)
  {
    cout << s << endl;
  }
}