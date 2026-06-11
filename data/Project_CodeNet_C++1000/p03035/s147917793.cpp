#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const long long  mod = 1000000007;



int main(){
  int a,b;
  cin >> a >> b;

  if(a >= 13) cout << b << endl;
  else if (a>5 && a <= 12) cout << b/2 << endl;
  else cout << 0 << endl;
  

}
