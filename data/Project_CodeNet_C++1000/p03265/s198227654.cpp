#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  int a,b,c,d ;
  cin >> a >> b >> c >> d ;
  
  int e,f,g,h ;
  e = c - (d-b) ;    
  f = d + (c-a) ;
  g = a - (d-b) ;
  h = b + (c-a) ;
  
  cout << e << " " << f << " " << g << " " << h << " " << endl ; 
}
