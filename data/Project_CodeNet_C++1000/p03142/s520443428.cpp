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
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> G(N);
  vector<ll> cling(N, 0);
  vector<ll> ans(N);
  for (ll i = 0; i < N + M - 1; i++)
  {
    ll A, B;
    cin >> A >> B;
    A--, B--;
    G.at(A).push_back(B);
    cling.at(B)++;
  }

  for (ll i = 0; i < N; i++)
  {
    if (cling.at(i) == 0)
    {
      ans.at(i) = -1;

      queue<ll> Q;
      Q.push(i);
      while (!Q.empty())
      {
        ll V = Q.front();
        Q.pop();

        for (auto nv : G.at(V))
        {
          cling.at(nv)--;
          if (cling.at(nv) == 0)
          {
            ans.at(nv) = V;
            Q.push(nv);
          }
        }
      }

      break;
    }
  }

  for (ll i = 0; i < N; i++)
  {
    cout << ans.at(i) + 1 << endl;
  }
}