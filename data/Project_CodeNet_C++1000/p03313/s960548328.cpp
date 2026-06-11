#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  std::vector<int> A(1<<N);
  for(int i=0;i<(1<<N);i++) std::cin >> A[i];
  vvi dp1 = vv(1<<N, N+1, 0, int);
  vvi dp2 = vv(1<<N, N+1, 0, int);
  for(int i=0;i<(1<<N);i++) dp1[i][0] = A[i], dp2[i][0] = 0;
  for(int j=0;j<N;j++){
    for(int i=0;i<(1<<N);i++){
      if(i&(1<<j)){
        dp1[i][j+1] = max(dp1[i &~(1<<j)][j], dp1[i][j]);
        dp2[i][j+1] = max({min(dp1[i &~(1<<j)][j], dp1[i][j]), dp2[i &~(1<<j)][j], dp2[i][j]});
      }
      else dp1[i][j+1] = dp1[i][j], dp2[i][j+1] = dp2[i][j];
    }
  }
  int ans = 0;
  for(int i=1;i<(1<<N);i++){
    ans = max(ans, dp1[i][N] + dp2[i][N]);
    std::cout << ans << '\n';
  }
  return 0;
}
