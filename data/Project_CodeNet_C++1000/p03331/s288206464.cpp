#include <bits/stdc++.h>
#define rep(i, a) for (ll i = 0; i < (a); ++i)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

ll digit(ll n){
  ll ans = 0;
  while(n >= 10){
    ans += n%10;
    n /= 10;
  }
  ans += n;
  return ans;
}

int main(){
  int n;
  cin >> n;
  vector<int> ans;
  for(int i=1;i<=n-1;i++){
    ans.pb(digit(i) + digit(n-i));
  }
  sort_1(ans);
  cout << ans[0] << endl;
}