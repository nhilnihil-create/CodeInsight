//Guidebook

#include <bits/stdc++.h>
using namespace std;

int main()
{

  int N;
  cin >> N;
  vector<tuple<string, int, int>> a(N);

  for (int i = 0; i < N; i++)
  {
    string S;
    int P;
    cin >> S >> P;
    P = -P; //点数を大きい順にするため
    a.at(i) = make_tuple(S, P, i + 1);
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < N; i++)
  {
    string S;
    int p;
    int id;
    tie(S, p, id) = a[i];
    cout << id << endl;
  }
}
