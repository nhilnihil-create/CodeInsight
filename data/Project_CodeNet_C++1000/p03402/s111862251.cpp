#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

int main()
{
  ll A, B;
  cin >> A >> B;

  vector<string> S(100);
  ll y, x;

  for (ll i = 0; i < 50; i++)
  {
    S.at(i) = string(100, '#');
  }
  y = 0, x = 0;
  for (ll i = 0; i < A - 1; i++)
  {
    S.at(y).at(x) = '.';

    x += 2;
    if (x >= 100)
      y += 2, x = 0;
  }

  for (ll i = 50; i < 100; i++)
  {
    S.at(i) = string(100, '.');
  }
  y = 51, x = 0;
  for (ll i = 0; i < B - 1; i++)
  {
    S.at(y).at(x) = '#';

    x += 2;
    if (x >= 100)
      y += 2, x = 0;
  }

  cout << "100 100" << endl;
  for (ll i = 0; i < 100; i++)
  {
    cout << S.at(i) << endl;
  }
}