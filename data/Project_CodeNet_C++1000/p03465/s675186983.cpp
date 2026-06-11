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
#define vvb std::vector<std::vector<bool> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N, S=0, ans;
  std::cin >> N;
  std::vector<int> A(N);
  for(int i=0;i<N;i++) {
    std::cin >> A[i];
    S += A[i];
  }
  ans = S;
  bitset<4000001> dp;
  dp.set(0);
  for(int i=0;i<N;i++){
    bitset<4000001> pd;
    pd = dp;
    pd |= dp << A[i];  //dp + A[i] || dp
    swap(dp, pd);
  }
  for(int i=(S+1)/2;i<4000001;i++) if(dp[i]){
    std::cout << i << '\n';
    return 0;
  }
  return 0;
}
