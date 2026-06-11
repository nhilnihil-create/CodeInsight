#include <bits/stdc++.h>
using namespace std;
int X, Y, Z, K;
priority_queue<tuple<int64_t, int, int, int>> PQ;

int main()
{
  cin >> X >> Y >> Z >> K;
  vector<int64_t> A(X), B(Y), C(Z);
  for (int i = 0; i < X; i++)
    cin >> A.at(i);
  for (int i = 0; i < Y; i++)
    cin >> B.at(i);
  for (int i = 0; i < Z; i++)
    cin >> C.at(i);
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  sort(C.begin(), C.end());
  reverse(C.begin(), C.end());
  int64_t ma = A.at(0) + B.at(0) + C.at(0);
  PQ.push(make_tuple(ma, 0, 0, 0));
  int64_t x, ia, ib, ic, k = 0;
  map<tuple<int, int, int>, bool> Checked;
  while (!PQ.empty())
  {
    tie(x, ia, ib, ic) = PQ.top();
    PQ.pop();
    if (ia + 1 < X && !Checked.count(make_tuple(ia + 1, ib, ic)))
    {
      int64_t na = A.at(ia + 1) + B.at(ib) + C.at(ic);
      PQ.push(make_tuple(na, ia + 1, ib, ic));
      Checked[make_tuple(ia + 1, ib, ic)] = true;
    }
    if (ib + 1 < Y && !Checked.count(make_tuple(ia, ib + 1, ic)))
    {
      int64_t nb = A.at(ia) + B.at(ib + 1) + C.at(ic);
      PQ.push(make_tuple(nb, ia, ib + 1, ic));
      Checked[make_tuple(ia, ib + 1, ic)] = true;
    }
    if (ic + 1 < Z && !Checked.count(make_tuple(ia, ib, ic + 1)))
    {
      int64_t na = A.at(ia) + B.at(ib) + C.at(ic + 1);
      PQ.push(make_tuple(na, ia, ib, ic + 1));
      Checked[make_tuple(ia, ib, ic + 1)] = true;
    }
    cout << x << endl;
    k++;
    if (k == K)
      break;
  }
}