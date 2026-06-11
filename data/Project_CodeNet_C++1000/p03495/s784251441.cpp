#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n+1);
  vector<int> c(n+1);
  for(int i = 0; i <= n; ++i){
    c[i] = 0;
  }
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    c[a[i]]++;
  }
  int p = 0;
  for(int i = 0; i <= n; ++i){
    if(c[i] != 0){
      ++p;
    }
  }
  sort(c.begin(),c.end());
  int res = 0;
  int j = 0;
  while(p > k){
    if(c[j] == 0){
      ++j;
      continue;
    }
    res += c[j];
    c[j] = 0;
    --p;
  }
  cout << res;
}