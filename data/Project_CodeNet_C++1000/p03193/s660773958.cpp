#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n,h,w ;
  cin >> n >> h >> w ; 
  int ans = 0 ;
  
  rep(i,n){
    int a,b ; 
    cin >> a >> b ; 
    if((h<=a) && (w<=b)) ans ++ ;
  }
  
  cout << ans << endl ;


}
