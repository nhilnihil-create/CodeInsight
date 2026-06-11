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
  ll K;
  cin >> K;

  deque<pair<ll, ll>> Q;
  vector<ll> dist(K, -1);
  Q.push_front(make_pair(1, 1));
  while (!Q.empty())
  {
    ll v = Q.front().first, w = Q.front().second;
    Q.pop_front();

    if (dist.at(v) != -1)
      continue;
    dist.at(v) = w;

    ll nv0 = (v * 10) % K;
    ll nv1 = (v + 1) % K;

    Q.push_front(make_pair(nv0, dist.at(v)));
    Q.push_back(make_pair(nv1, dist.at(v) + 1));

    //cerr << v << " " << nv0 << " " << nv1 << endl;
  }

  ll ans = dist.at(0);
  cout << ans << endl;

  /*
  for (ll i = 0; i < K; i++)
  {
    cerr << i << " " << dist.at(i) << endl;
  }
  */
}