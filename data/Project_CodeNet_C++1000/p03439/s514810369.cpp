#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divCeil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << A << endl; exit(0);}

string ans;
vector<string> S;
void ANS(ll A)
{
  cout << A << endl
       << flush;
  cin >> ans;

  if (ans == "Vacant")
    exit(0);
  S.at(A) = ans;
}

int main()
{
  ll N;
  cin >> N;

  S.resize(N + 1);

  ll L = 0, R = N;
  ANS(0);
  S.at(N) = ans;
  for (ll i = 0; i < 19; i++)
  {
    ll C = (L + R) / 2;
    ANS(C);

    if ((C - L) % 2 == 1)
    {
      if (S.at(L) == S.at(C))
        R = C;
      else
        L = C;
    }
    else
    {
      if (S.at(L) == S.at(C))
        L = C;
      else
        R = C;
    }
  }
}