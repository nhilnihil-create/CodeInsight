#include <bits/stdc++.h>
#define INF 1000000000000000001
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N;
vector<vector<bool>> ans;
vector<vector<char>> board;
void start_check(ll a, ll b)
{
  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j < N; ++j)
    {
      if (board.at(a + i).at(b + j) == board.at(a + j).at(b + i))
      {
        continue;
      }
      else
      {
        ans.at(a).at(b) = false;
        ll bad_num = min(i, j);
        for (ll k = 0; k < bad_num + 1; ++k)
        {
          if (a + k >= N || b + k >= N)
          {
            break;
          }
          ans.at(a + k).at(b + k) = false;
        }
        return;
      }
    }
  }
}

void check(ll a, ll b)
{
  for (ll i = 0; i < N - 1; ++i)
  {
    if (board.at(a + i).at(b + N - 1) == board.at(a + N - 1).at(b + i))
    {
      continue;
    }
    for (ll j = 0; j < i + 1; ++j)
    {
      ans.at(a + j).at(b + j) = false;
    }
    return;
  }
  return;
}

int main()
{
  cin >> N;
  board = vector<vector<char>>(2 * N - 1, vector<char>(2 * N - 1));
  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j < N; ++j)
    {
      char s;
      cin >> s;
      board.at(i).at(j) = s;
      if (i + N < 2 * N - 1)
      {
        board.at(i + N).at(j) = s;
        if (j + N < 2 * N - 1)
        {
          board.at(i + N).at(j + N) = s;
        }
      }
      if (j + N < 2 * N - 1)
      {
        board.at(i).at(j + N) = s;
      }
    }
  }
  ans = vector<vector<bool>>(N, vector<bool>(N, true));
  // start_check(0, 0, ans, board);
  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j < N; ++j)
    {
      if (!ans.at(i).at(j))
      {
        continue;
      }
      if (i == 0 || j == 0)
      {
        start_check(i, j);
      }
      else if (ans.at(i - 1).at(j - 1))
      {
        check(i, j);
      }
      else
      {
        start_check(i, j);
      }
    }
  }
  // for (ll i = 0; i < N; ++i)
  // {
  //   for (ll j = 0; j < N; ++j)
  //   {
  //     if (ans.at(i).at(j))
  //     {
  //       cout << 1;
  //     }
  //     else
  //     {
  //       cout << 0;
  //     }
  //   }
  //   cout << endl;
  // }
  //
  //
  // for (ll i = 0; i < 2 * N - 1; ++i)
  // {
  //   for (ll j = 0; j < 2 * N - 1; ++j)
  //   {
  //     cout << board.at(i).at(j);
  //   }
  //   cout << endl;
  // }
  ll cnt = 0;
  for (ll i = 0; i < N; ++i)
  {
    for (ll j = 0; j < N; ++j)
    {
      if (ans.at(i).at(j))
      {
        cnt += 1;
      }
    }
  }
  cout << cnt << endl;
}
