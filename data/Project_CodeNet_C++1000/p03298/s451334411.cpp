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

ll N;
string S, T;
map<pair<string, string>, pair<ll, ll>> mp;
void dfs(bool isS, string s0, string s1, ll cnt)
{
  if (cnt == N)
  {
    if (isS)
      mp[make_pair(s0, s1)].first++;
    else
      mp[make_pair(s0, s1)].second++;
    return;
  }

  dfs(isS, s0 + ((isS) ? S : T).at(cnt), s1, cnt + 1);
  dfs(isS, s0, s1 + ((isS) ? S : T).at(cnt), cnt + 1);
}

int main()
{
  cin >> N;
  string s0;
  cin >> s0;

  S = s0.substr(0, N), T = s0.substr(N, N);
  reverse(T.begin(), T.end());

  dfs(true, "", "", 0);
  dfs(false, "", "", 0);

  ll ans = 0;
  for (auto x : mp)
  {
    //cerr << x.first.first << " " << x.first.second << " ";
    //cerr << x.second.first << " " << x.second.second << endl;
    ans += x.second.first * x.second.second;
  }
  cout << ans << endl;
}