#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < int(n);i++)

int pow(int b,int p){
  int res= 1;
  rep(i,p) res*=b;
  return res;
}

int main(){
  int x;
  cin >> x;
  int ans = 0;
  for (int i = 1;i <= x;i++){
    for (int j = 2; j < 10;j++){
      int tmp = pow(i,j);
      if (tmp > x) break;
      ans = max(ans,tmp);
    }
  }
  cout << ans << endl;

  

  return 0;
}