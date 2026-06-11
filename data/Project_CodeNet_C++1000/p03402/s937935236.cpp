#include <bits/stdc++.h>
using namespace std;
#define rep(i, from, to) for (int i = from; i < to; i++)
int main()
{
  int A, B;
  cin >> A >> B;
  string pa[2] = {"#.###", "###.#"};
  string pb[2] = {".#...", "...#."};
  string pW = ".....";
  string pB = "#####";
  cout << "100 100" << endl;
  rep(i, 0, 49)
  {
    rep(j, 0, 20)
    {
      if (--A > 0)
        cout << pa[i % 2];
      else
        cout << pB;
    }
    puts("");
  }
  rep(i, 0, 20) cout << pW;
  puts("");
  rep(i, 0, 50)
  {
    rep(j, 0, 20)
    {
      if (--B > 0)
        cout << pb[i % 2];
      else
        cout << pW;
    }
    puts("");
  }
  return 0;
}
