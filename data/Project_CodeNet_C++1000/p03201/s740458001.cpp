#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n;
  cin >> n;
  vector < int > a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  multiset < int > s(a.begin(), a.end());

  int ans = 0;
  while(!s.empty()){
    auto it = prev(s.end());
    int x = *it;
    int y = (1 << (32 - __builtin_clz(x))) - x;
    s.erase(it);
    it = s.find(y);
    if(it != s.end()){
      ans++;
      s.erase(it);
    }
  }

  cout << ans << '\n';
}
