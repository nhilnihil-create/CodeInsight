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

signed main()
{
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++)
  {
    string s;
    cin >> s;
    s += s.substr(0, s.size() - 1);
    S.at(i) = s;
  }
  
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    bool ok = true;
    for (int j = 0; j < N; j++)
    {
      for (int k = 0; k < N; k++)
      {
        if (S.at(j).at(k + i) != S.at(k).at(j + i))
        {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) ans += N;
  }
  
  cout << ans << endl;
}