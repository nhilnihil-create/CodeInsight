#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
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
  string S;
  cin >> S;
  S += 'T';
  ll N = S.size();
  ll X, Y;
  cin >> X >> Y;

  vector<ll> A, B;
  ll cnt = 0;
  bool isA = true;
  bool first = true;
  for (ll i = 0; i < N; i++)
  {
    if (S.at(i) == 'T')
    {
      if (first)
      {
        first = false;
        X -= cnt;
      }
      else
      {
        if (isA)
          A.push_back(cnt);
        else
          B.push_back(cnt);
      }

      cnt = 0;
      isA = !isA;
    }
    else
    {
      cnt++;
    }
  }

  X = abs(X), Y = abs(Y);
  ll sumA = accumulate(A.begin(), A.end(), 0LL);
  ll sumB = accumulate(B.begin(), B.end(), 0LL);
  if (sumA < X || sumB < Y)
    FINALANS("No");
  if ((sumA + X) % 2 != 0 || (sumB + Y) % 2 != 0)
    FINALANS("No");
  ll P = (sumA + X) / 2, Q = (sumB + Y) / 2;

  cerr << "A" << endl;

  vector<vector<int>> dpx(A.size() + 1, vector<int>(sumA + 1, 0));
  dpx.at(0).at(0) = 1;
  for (ll i = 0; i < A.size(); i++)
  {
    for (ll j = 0; j <= sumA; j++)
    {
      if (j + A.at(i) <= sumA)
        dpx.at(i + 1).at(j + A.at(i)) |= dpx.at(i).at(j);
      dpx.at(i + 1).at(j) |= dpx.at(i).at(j);
    }
  }
  if (!dpx.at(A.size()).at(P))
    FINALANS("No");
  
  vector<vector<int>> dpy(B.size() + 1, vector<int>(sumB + 1, 0));
  dpy.at(0).at(0) = 1;
  for (ll i = 0; i < B.size(); i++)
  {
    for (ll j = 0; j <= sumB; j++)
    {
      if (j + B.at(i) <= sumB)
        dpy.at(i + 1).at(j + B.at(i)) |= dpy.at(i).at(j);
      dpy.at(i + 1).at(j) |= dpy.at(i).at(j);
    }
  }
  if (!dpy.at(B.size()).at(Q))
    FINALANS("No");

  FINALANS("Yes");
}