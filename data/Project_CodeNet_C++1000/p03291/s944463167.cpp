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
  string S;
  cin >> S;
  int N = S.size();

  vector<vector<int>> dp(N + 1, vector<int>(4, 0));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < N; i++)
  {
    string ABC = "ABC";
    for (int j = 0; j < 4; j++)
    {
      if (j != 3 && (S.at(i) == '?' || S.at(i) == ABC.at(j)))
      {
        dp.at(i + 1).at(j + 1) += dp.at(i).at(j);
        dp.at(i + 1).at(j + 1) %= MOD;
      }
      
      dp.at(i + 1).at(j) += dp.at(i).at(j) * ((S.at(i) == '?')? 3 : 1);
      dp.at(i + 1).at(j) %= MOD;
    }
  }
  
  int ans = dp.at(N).at(3);
  cout << ans << endl;
}