#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main(){
  std::vector<int> v(3);
  rep(i,3)std::cin >> v[i];

  int ans=0;
  while (!((v[0]==v[1]) && (v[1]==v[2]) )) {

    sort(v.begin(),v.end());
    // std::cout << v[0] << ' '<<v[1]<<' ' <<v[2]<<'\n';
    if(v[0]+1<= v[2] && v[1]+1<=v[2]){
      v[0]++;
      v[1]++;
    }
    else if(v[0]+2<=v[2])v[0]+=2;
    else {
      ans+=2;
      break;
    }
    ans++;
  }
  std::cout << ans << '\n';
  return 0;
}
