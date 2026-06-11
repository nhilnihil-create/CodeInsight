#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18

using namespace std;

int main(void){
  ll n;
  string s;
  cin >> n >> s;
  
  
  
  int a[26] = {};
  for (int i = 0; i < n; i++){
    a[s[i]-'a']++;
  }
  ll ans = 1;
  for (int i = 0; i < 26; i++){
    ans = ans * (a[i] + 1) % MOD;
  }

  ans--;
  cout << ans << endl;

  return 0;
}
