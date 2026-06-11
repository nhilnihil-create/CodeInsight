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
  ll N;
  cin >> N;

  multiset<ll> st;
  for (ll i = 0; i < N; i++)
  {
    ll A;
    cin >> A;
    st.emplace(A);
  }

  ll ans = 0;
  while (!st.empty())
  {
    ll a = *st.rbegin();
    ll b = (1LL << ((ll)log2(a) + 1)) - a;

    st.erase(st.find(a));
    if (st.count(b) > 0)
    {
      st.erase(st.find(b));
      ans++;
    }
  }

  cout << ans << endl;
}