#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll H, W, N;
  cin >> H >> W >> N;
  ll sr, sc;
  cin >> sr >> sc;
  string S, T;
  cin >> S >> T;
  vector<ll> lrud(4, 0);
  vector<ll> need = {sc, W - sc + 1, sr, H - sr + 1};
  vector<char> move = {'L', 'R', 'U', 'D'};
  // bool fin = false;
  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j < 4; ++j)
    {
      if (S[i] == move.at(j))
      {
        lrud.at(j) += 1;
      }
    }
    for (ll k = 0; k < 4; ++k)
    {
      if (lrud.at(k) >= need.at(k))
      {
        cout << "NO" << endl;
        return 0;
        // fin = true;
        // break;
      }
    }
    // if (fin)
    // {
    //   break;
    // }
    for (ll j = 0; j < 4; ++j)
    {
      // cout << "J" << j << "fix" << (j + 1) % 2 + (j / 2) * 2 << endl;
      if (T[i] == move.at(j) && lrud.at((j + 1) % 2 + (j / 2) * 2) != -need.at(j) + 1)
      {
        lrud.at((j + 1) % 2 + (j / 2) * 2) -= 1;
      }
    }
  }
  // cout << "need" << endl;
  // for (ll i = 0; i < 4; ++i)
  // {
  //   cout << need.at(i) << ' ';
  // }
  // cout << endl;
  // cout << "lrud" << endl;
  // for (ll i = 0; i < 4; ++i)
  // {
  //   cout << lrud.at(i) << ' ';
  // }
  // cout << endl;
  cout << "YES" << endl;
}
