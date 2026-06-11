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
  ll N, K;
  cin >> N >> K;

  vector<vector<ll>> P(N);
  for (ll i = 0; i < N; i++)
  {
    ll t, d;
    cin >> t >> d;
    t--;
    P.at(t).push_back(d);
  }

  for (auto &p : P)
  {
    if (p.empty())
      p.push_back(-(K * K + 10));
    sort(p.begin(), p.end(), greater<ll>());
  }
  sort(P.begin(), P.end(),
       [](const vector<ll> &a, const vector<ll> &b)
          { return (a.front() > b.front()); });

  priority_queue<ll> Q;
  ll tmp = 0;
  for (ll i = 0; i < K; i++)
  {
    tmp += P.at(i).front();
    for (ll j = 1; j < P.at(i).size(); j++)
    {
      Q.push(P.at(i).at(j));
    }
  }
  for (ll i = K; i < N; i++)
  {
    for (ll j = 0; j < P.at(i).size(); j++)
    {
      Q.push(P.at(i).at(j));
    }
  }

  ll ans = tmp + K * K;
  for (ll x = K - 1; x > 0; x--)
  {
    ll v = P.at(x).front();
    ll w = Q.top();
    if (v < w)
    {
      Q.pop(), Q.push(v);
      tmp -= v, tmp += w;
    }

    chmax(ans, tmp + x * x);
  }
  cout << ans << endl;
}