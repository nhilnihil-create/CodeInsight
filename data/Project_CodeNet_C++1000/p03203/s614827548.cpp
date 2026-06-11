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
  int H, W, N, ans;
  std::cin >> H >> W >> N;
  ans = H;
  vvi bl = vv(N, 2, 0, int);
  for(int i=0;i<N;i++) std::cin >> bl[i][1] >> bl[i][0];
  sort(bl.begin(), bl.end());
  int now = 0;
  for(int i=0;i<N;i++){
    if(bl[i][1]-bl[i][0]-now>0) ans = min(ans, bl[i][1]-1);
    else if(bl[i][1]-bl[i][0]==now) now++;
    //std::cout <<bl[i][0] << " " << bl[i][1] << " " << i+1 << " " << ans  << " " << now << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
