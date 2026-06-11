#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define int_Max 2147483647
#define ll_Max 9223372036854775807
#define REP(i,f,n) for(int i=f; i<(n); i++)

int main()
{
  ll ans = 0, w=0;
  string s;
  cin >> s;
  ll n = s.length();
  REP(i,0,n){
    if(s[i] == 'W'){
      ans += i-w;
      w++;
    }
  }

  cout << ans << endl;

  //--debug : end_stoper
  //string end_stoper; cin >> end_stoper;

  return 0;
}