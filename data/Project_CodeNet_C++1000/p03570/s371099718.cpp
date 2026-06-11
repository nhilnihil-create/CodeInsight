#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
using namespace std;
const int INF = 1<<30;
string S;
vector<int> dp(200010, INF);
vector<int> best(1<<26, INF);

int main(){
  cin >> S;
  int sl = S.size();
  vector<int> A(sl+1);
  A[0] = 0;
  for(int i = 1; i <= sl; i++){
    A[i] = A[i-1] ^ (1<<(S[i-1] - 'a'));
  }
  best[0] = 0;
  dp[0] = 0;
  for(int i = 1; i <= sl; i++){
    int x = A[i];
    for(int j = -1; j < 26; j++){
      int nx = x;
      if(j >= 0) nx ^= (1<<j);
      dp[i] = min(dp[i], best[nx] + 1);
    }
    best[x] = min(best[x], dp[i]);
  }
  cout << dp[sl] << endl;
}
