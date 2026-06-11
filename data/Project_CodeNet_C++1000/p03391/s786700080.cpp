#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  ll INF = 1000000007;
  std::cin >> N;
  ll sa = INF, S=0;
  std::vector<int> A(N), B(N);
  for(int i=0;i<N;i++){
    std::cin >> A[i] >> B[i];
    S+=A[i];
    if(A[i]>B[i]) sa = (sa>B[i]?B[i]:sa);
  }
  if(sa==INF) std::cout << 0 << '\n';
  else std::cout << S - sa << '\n';
  return 0;
}
