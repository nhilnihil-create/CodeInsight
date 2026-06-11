#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <tuple>
#include <set>
#include <map>
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
  int H, W, N, sr, sc;;
  string S, T;
  std::cin >> H >> W >> N;
  std::cin >> sr >> sc;
  std::cin >> S >> T;
  pair<int, int> win_ul{1, 1}, win_lr{H, W};
  vvi win = vv(N, 4, 0, int);
  for(int i=N-1;i>=0;i--){
    if(S[i]=='L'){
      win_ul.second++;
    }else if(S[i]=='R'){
      win_lr.second--;
    }else if(S[i]=='U'){
      win_ul.first++;
    }else{
      win_lr.first--;
    }
    if(T[i]=='L'){
      if(win_lr.second<W) {
        win_lr.second++;
        if(win_lr.second==W&&S[i]=='R') win_lr.second--;
      }
    }else if(T[i]=='R'){
      if(win_ul.second>1){
         win_ul.second--;
         if(win_ul.second==1&&S[i]=='L') win_ul.second++;
      }
    }else if(T[i]=='U'){
      if(win_lr.first<H) {
        win_lr.first++;
        if(win_lr.first==H&&S[i]=='D') win_lr.first--;
      }
    }else{
      if(win_ul.first>1) {
        win_ul.first--;
        if(win_ul.first==1&&S[i]=='U') win_ul.first++;
      }
    }
    win[i][0]=win_ul.first;
    win[i][1]=win_ul.second;
    win[i][2]=win_lr.first;
    win[i][3]=win_lr.second;
    if(win[i][0]>win[i][2]|win[i][1]>win[i][3]){
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  if(win[0][0]<=sr&& win[0][1]<=sc && win[0][2]>=sr &&win[0][3]>=sc){
    std::cout << "YES" << '\n';
  }else{
    std::cout << "NO" << '\n';
  }

  /*for(int i=0;i<N;i++){
    for(int j=1;j<=H;j++){
      for(int k=1;k<=W;k++){
        if(win[i][0]<=j&& win[i][1]<=k && win[i][2]>=j &&win[i][3]>=k){
          std::cout << "#";
        }else{
          std::cout << ".";
        }
      }
      std::cout << '\n';
    }
    std::cout << win[i][0] << win[i][1] << win[i][2] << win[i][3] << '\n';
    std::cout << '\n';
    std::cout << '\n';
  }*/

  return 0;
}
