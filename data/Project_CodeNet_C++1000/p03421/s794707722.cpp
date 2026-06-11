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
  ll N, A, B;
  std::cin >> N >> A >> B;
  if(A+B>N+1||A*B<N){std::cout << -1 << '\n';return 0;}
  if(B==1) for(int i=1;i<=N;i++) std::cout << i << (i==N?"\n":" ");
  else{
    int now = 0;
    int count = N - A;
    std::vector<int> ans;
    for(int i=1; count>0;i++, count-=B-1) {
      for(int j=min(i*B, (i-1)*B+count+1);j>(i-1)*B;j--){
        now = max(now, j);
        ans.push_back(j);
      }
    }
    for(int i=now+1;i<=N;i++) ans.push_back(i);
    for(int i=0;i<ans.size();i++) std::cout << ans[i] << (i==N-1?"\n":" ");
  }
  return 0;
}
