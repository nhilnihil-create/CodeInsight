#include <bits/stdc++.h>
using namespace std;
using  ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){

  int n;
  int ans=0;
  std::cin >> n;


  for (int i = 1; i <=n ; i+=2) {
    int temp=i;
    int na=0;
    // printf("%d\n",i);
    for (int j = 1; j <= i ; j++) {
      if(temp%j==0){na++;}
    }
    if(na==8)ans++;

  }
  std::cout << ans << '\n';



  return 0;
}
