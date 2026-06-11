#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,k,a[300000],num[300000];
  cin >> n >> k;
  for(int i = 0; i <= n; i++)
    num[i] = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    num[a[i]]++;
  }

  int cnt = 0;
  for(int i = 0; i <= n; i++)
    if(num[i] != 0) cnt++;
  
  if(cnt <= k) {
    cout << 0 << endl;
    return 0;
  }

  sort(num,num+n+1,greater<int>());
  int ans = 0;
  for(int i = k; i <= n; i++)
    ans += num[i];

  cout << ans << endl;
}