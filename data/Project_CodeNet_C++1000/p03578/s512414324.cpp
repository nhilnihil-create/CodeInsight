#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;


int main() {
  map<int,int> data ;
  int n , m ; 
  cin >> n  ; 
  string ans = "YES" ; 
  
  rep(i,n){
    int p ; 
    cin >> p ; 
    data[p] ++ ;
  }
  
  cin >> m ; 
  
  rep(i,m){
    int p ; 
    cin >> p ; 
    data[p] -- ; 
    if(data[p] <0 ) ans = "NO" ;
  }
  
  cout << ans ;
  
  
}
