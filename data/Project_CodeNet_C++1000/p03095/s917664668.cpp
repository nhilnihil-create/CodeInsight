#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define REPvec(itr, mp) for(auto itr = mp.begin();itr != mp.end(); itr ++)
#define all(x) x.begin(), x.end()
#define MOD 1000000007//1e9+7
using namespace std;
typedef long long ll;
typedef vector<bool>    vecbool;
typedef vector<int>     vecint;
typedef vector<ll>      vecll;
typedef vector<string>  vecstr;
typedef vector<vecint>  vec2int;
typedef vector<vecbool> vec2bool;
int dx[4] {-1,+1, 0, 0};
int dy[4] { 0, 0,-1,+1};
int main()
{
  int n; cin >> n;
  string s; cin >> s;
  map<char, ll> mp;
  REP(i,n){
    mp[s[i]]++;
  }
  for(char c = 'a'; c <= 'z'; c++){
    mp[c] ++;
  }
  ll ans = 1;
  for(char c = 'a'; c <= 'z'; c++){
    ans *= mp[c];
    ans %= MOD;
  }
  if(ans == 0){
    ans = MOD-1;
  }else{
    ans -= 1;
  }
  cout << ans << endl;
}
