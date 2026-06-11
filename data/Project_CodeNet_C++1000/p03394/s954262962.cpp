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
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;

  vector<ll> A = {2, 3, 25};

  ll cnt = 5;
  while (A.size() < N)
  {
    if (N - A.size() == 1)
      A.push_back(30000);
    else
    {
      while (cnt == 25 || !(cnt % 2 == 0 || cnt % 3 == 0 || cnt % 5 == 0))
      {
        cnt++;
      }
      A.push_back(cnt);
      A.push_back(30000 - cnt);
      cnt++;
    }
  }

  for (ll i = 0; i < N; i++)
  {
    cout << A.at(i) << ((i == N - 1) ? '\n' : ' ');
  }

  /*
  ll S = accumulate(A.begin(), A.end(), 0LL);
  map<ll, ll> mp;
  for (ll i = 0; i < N; i++)
  {
    ll a = A.at(i), b = S - a;
    if (!(a % 2 == 0 || a % 3 == 0 || a % 5 == 0))
    {
      cerr << "No_0" << endl;
      return 0;
    }
    mp[a]++;
  }
  cerr << mp.size() << endl;
  cerr << ((mp.size() == N) ? "Yes" : "No_1") << endl;

  for (auto x : mp)
  {
    if (x.second == 2)
      cerr << x.first << endl;
  }
  */
}