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
  int N, K, Q, INF=1000000007, ans = INF;
  cin >> N >> K >> Q;
  vector<int> A(N);
  for(int i=0;i<N;i++) std::cin >> A[i];

  for(int i=0;i<N;i++){
    vvi s = vv(3000, 0, 0, int);
    vector<int> candi;
    int now = 0;
    for(int j=0;j<N;j++){
      if(A[j]>=A[i]) s[now].push_back(A[j]);
      else if(s[now].size()!=0) now++;
    }
    for(int j=0;j<=now;j++) if(s[j].size()!=0) sort(s[j].begin(), s[j].end());
    for(int j=0;j<=now;j++){
      if(s[j].size()==0) continue;
      for(int k=0;k+K-1<s[j].size();k++) candi.push_back(s[j][k]);
    }
    sort(candi.begin(), candi.end());
    /*
    for(int j=0;j<=now;j++){
      for(int k=0;k<s[j].size();k++) std::cout << s[j][k] << " ";
      std::cout << '\n';
    }
    std::cout << "candi" << '\n';
    for(int j=0;j<candi.size();j++) std::cout << candi[j] << " ";
    std::cout << '\n';
    */

    if(candi.size()<Q) continue;
    ans = min(ans, candi[Q-1] - A[i]);
  }
  std::cout << ans << '\n';
  return 0;
}
