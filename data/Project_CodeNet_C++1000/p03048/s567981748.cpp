#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int) n; i++)
using ll = long long;
template <class T>
using vt = std::vector<T>;
using vvi = std::vector<vt<int>>;

int main(){
  int R,G,B,N;
  std::cin >> R >> G >> B >> N;

  int cnt = 0;
  int maxi = std::max({R,G,B});
  int mini = std::min({R,G,B});
  int mid = R+G+B - maxi - mini;
  rep(i,N/maxi+1){
    rep(j,N/mid+1){
      int a = N - maxi*i - mid*j;
      if(a < 0) break;
      else if(a%mini == 0) cnt++;
    }
  }

  std::cout << cnt << '\n';
  return 0;
}
