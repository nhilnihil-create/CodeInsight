#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << '\n'
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define pr(s) cout << (s) << '\n'
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;
const ll INFll = 1E+18;

int main() {
  int a, b;
  cin >> a >> b;
  string ans = "x";
  if (a+b==15) ans = "+";
  if (a*b==15) ans = "*";
  pr(ans);
}