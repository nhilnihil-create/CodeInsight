#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#define vll vector<ll>
#define vvvl vector<vvl>
#define vvl vector<vector<ll>>
#define VV(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define VVV(a, b, c, d) vector<vvl>(a, vvl(b, vll (c, d)));
#define re(c, b) for(ll c=0;c<b;c++)
#define all(obj) (obj).begin(), (obj).end()
typedef long long int ll;
typedef long double ld;
using namespace std;

ll P = 1000000007;
int main(int argc, char const *argv[]) {
  ll n;std::cin >> n;
  string s;std::cin >> s;
  // dp[i][j] := i個見て、最後のもの未満で選べるものがj個ある
  vvl dp = VV(n+1, n+1, 0, ll);
  for(int i=0;i<n;i++) dp[0][i] = 1;//始めがi

  //貰う
  vll accum(n, 0);
  for(int i=1;i<n;i++){
    //accumの初期化
    for(int j=0;j<n;j++) accum[j] = ((j==0?0:accum[j-1]) + dp[i-1][j])%P;

    for(int j=0;j<n-i;j++){
      if(s[i-1]=='<'){
        //0~jから到達できる
        dp[i][j] = accum[j];
      }else{
        //j+1~maxから到達できる
        dp[i][j] = (accum[n-i] - accum[j] + P)%P;
      }
    }

  }
  std::cout << dp[n-1][0] << '\n';
  return 0;
}
