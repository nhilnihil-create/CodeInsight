#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
  int n,k; string s;
  cin >> n >> k >> s;

  int ans = 1;
  int l=0, r=0;

  while(r<n && s[r] == '1') r++;

  while(k > 0 && r < n) {
    while(r<n && s[r] == '0') r++;
    while(r<n && s[r] == '1') r++;
    k--;
  }

  ans = max(ans, r - l); 

  while(r<n) {
    ans = max(ans, r - l); 
    while(l<r-1 && s[l] == '1') l++;
    while(l<r-1 && s[l] == '0') l++;

    while(r<n && s[r] == '0') r++;
    while(r<n && s[r] == '1') r++;
    ans = max(ans, r - l); 
  }
  cout << ans << endl;
}
