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
  ll N, a, b, ans = 0;
  std::cin >> N;
  std::vector<int> R, L;
  for(int i=0;i<N;i++){
    std::cin >> a >> b;
    R.push_back(a), L.push_back(b);
  }
  sort(R.begin(), R.end(), [](ll a, ll b){return a > b;});
  sort(L.begin(), L.end());
  ll now = 0;
  for(int i=0;i<N;i++){
    //std::cout << L[i] << " " << R[i] << '\n';
    ans = max(ans, now+2*R[i]);
    now += 2*R[i] - 2*L[i];
    ans = max(ans, now);
  }

  now = 0;
  for(int i=0;i<N;i++){
    //std::cout << now << " " << now - 2*L[i] << '\n';
    ans = max(ans, now-2*L[i]);
    now += 2*R[i] - 2*L[i];
    ans = max(ans, now);
  }
  std::cout << ans << '\n';
  return 0;
}
