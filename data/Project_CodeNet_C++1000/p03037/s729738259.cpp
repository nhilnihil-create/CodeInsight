#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int n , m ; 
  cin >> n >> m  ;
  int l=0 , r = INF ;
  rep(i,n){
    int a,b ; 
    cin >> a >> b ; 
    l = max(l,a) ; 
    r = min(r,b);
  }
  
  if(r-l+1 < 0 ) cout << 0  <<endl ;
  else           cout << r- l + 1 <<endl ;
    


}
