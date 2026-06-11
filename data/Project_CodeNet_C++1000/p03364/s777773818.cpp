#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#define range(i, r) for(int i=0;i<r;i++)
#define ranges(i, l, r) for(int i=l;i<r;i++)
#define vv(a, b, c, d) vector<vector<d> >(a, vector<d>(b, c))
#define vvi std::vector<std::vector<int> >
#define vvl std::vector<std::vector<ll> >
#define MODs 1000000007;
#define MODn 1000000009;
typedef long long int ll;
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  std::vector<string> S(2*N);
  range(i, N) {
    std::cin >> S[i];
    S[i] = S[i] + S[i];
  }
  //range(i, N) std::cout << S[i] << '\n';
  ranges(i, N, 2*N) S[i] = S[i-N];
  std::vector<int> st(2*N-1);
  range(i, N-1){
    st[i] = N-1-i;
  }
  st[N-1] = 0;
  ranges(i, N, 2*N-1){
    st[i] = i - N + 1;
  }
  int x = 0,y = 0, ans = 0, point;
  for(int i=0;i<2*N-1;i++){
    if(i<N-1) x=0,y=st[i], point=i+1;
    else if(i==N-1) x = y = 0, point=N;
    else x=st[i], y=0, point = N - (i - N) - 1;
    //std::cout << point << '\n';
    //std::cout << x << y << '\n';
    bool flag = true;
    for(int j=0;j<N;j++){
      for(int k=0;k<N;k++){
        if(S[x+k][y+j]!= S[x+j][y+k]) flag = false;
      }
    }
    if(flag) ans+=point;
  }
  std::cout << ans << '\n';
  return 0;
}
