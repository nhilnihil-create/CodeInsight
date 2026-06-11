#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  string s;
  cin >> s;
  
  ll ans = 700;
  for (int i = 0; i < 3; i++){
    if (s[i] == 'o')
      ans += 100;
  }
  cout << ans << endl;

  return 0;
}
