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
#define FINALANS(A) do {cout << (A) << '\n'; exit(0);} while (false)

int main()
{
  ll M, K;
  cin >> M >> K;

  if ((1LL << M) <= K)
    FINALANS(-1);
  
  if (M == 0)
  {
    if (K == 0)
      FINALANS("0 0");
    else
      FINALANS(-1);
  }

  if (M == 1)
  {
    if (K == 0)
      FINALANS("0 0 1 1");
    else
      FINALANS(-1);
  }

  for (ll i = 0; i < (1LL << M); i++)
  {
    if (i != K)
      cout << i << " ";
  }
  cout << K << " ";
  for (ll i = (1LL << M) - 1; i >= 0; i--)
  {
    if (i != K)
      cout << i << " ";
  }
  cout << K << endl;
}