#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,A1[110],A2[110];
  cin >> n;

  for(int i = 0; i < n; i++)
    cin >> A1[i];
  for(int i = 0; i < n; i++)
    cin >> A2[i];

  int ans = 0;
  for(int i = 0; i < n; i++) {
    int count = 0;
    for(int j = 0; j < n; j++) {
      if(i+j < n) count += A1[j];
      if(n-i-1+j < n) count += A2[n-i-1+j];
    }
    ans = max(ans,count);
  }
  cout << ans << endl;
}