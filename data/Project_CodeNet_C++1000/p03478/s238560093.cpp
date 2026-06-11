#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MX = 100001;

int main(){
  int n,a,b;
  cin >> n >> a >> b;

  int ans = 0;

  for(int i=1; i<=n; i++){
    int tmp = i;
    
    //各桁の和を求める
    int tot = 0;
    while(tmp>0){
      tot += tmp % 10;
      tmp /= 10;
    }

    if(a<=tot&&tot<=b) ans += i;
  }

  cout << ans << endl;
  
  return 0;
}