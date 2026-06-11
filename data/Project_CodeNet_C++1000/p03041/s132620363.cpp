#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  for (int i = 0; i < N; i++)
  {
    if (i + 1 == K && S.at(i) == 'A')
    {
      S.at(i) = 'a';
    }
    else if (i + 1 == K && S.at(i) == 'B')
    {
      S.at(i) = 'b';
    }
    else if (i + 1 == K && S.at(i) == 'C')
    {
      S.at(i) = 'c';
    }
  }
  cout << S << endl;
}