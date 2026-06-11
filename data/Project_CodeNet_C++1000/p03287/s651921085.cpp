#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector < ll > a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  map < int, int > mp;

  mp[0] = 1;
  ll sum = 0, ans = 0;
  for(int i = 1; i <= n; i++){
    sum += a[i];
    sum %= m;
    ans += mp[sum];
    mp[sum]++;
  }

  cout << ans << '\n';
}
