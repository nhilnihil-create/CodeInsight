#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, m;
  cin >> n >> m;
  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  vector<int> s(n+1);
  s[0] = 0;
  for(int i=0; i<n; i++){
    s[i+1] = (s[i]+a[i])%m;
  }
  map<int, int> mp;
  ll ans = 0;
  for(int i=0; i<=n; i++){
    ans += mp[s[i]];
    mp[s[i]]++;
  }
  cout << ans << endl;
  return 0;
}
