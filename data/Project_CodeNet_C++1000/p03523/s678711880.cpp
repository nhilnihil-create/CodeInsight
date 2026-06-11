#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = pow(10, 9) + 7;
//const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}
int myctoi(char C) {return C - 48;}
char myitoc(int N) {return '0' + N;}

vector<string> ok;
vector<int> p = {5, 4, 3, 0};
void dfs(string S, int N)
{
  if (N == 4) return;

  string SS = S;
  SS.insert(p.at(N), "A");
  ok.push_back(SS);
  
  dfs(SS, N + 1);
  dfs(S, N + 1);
}

signed main()
{
  string S;
  cin >> S;
  
  ok.push_back("KIHBR");
  dfs("KIHBR", 0);

  auto itr = find(ok.begin(), ok.end(), S);

  string ans = (itr != ok.end()) ? "YES" : "NO";
  cout << ans << endl;
}