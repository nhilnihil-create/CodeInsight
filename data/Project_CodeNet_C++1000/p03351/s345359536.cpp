#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long

int main() {
  int a , b , c , d ;
  cin >> a >> b >> c >> d ;
  
  string ans = "No";
  if( max(a,c)-min(a,c) <=d ) 
    ans = "Yes";
  
  else if( (min(a,c) <= b) && (b <= max(a,c))){
    if((b- (min(a,c) <= d) && (max(a,c) - b <= d )))
       ans =  "Yes";
  }

  cout << ans;
       

}
