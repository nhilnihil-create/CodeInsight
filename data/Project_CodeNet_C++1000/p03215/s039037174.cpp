#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <climits>
#include <utility>
#include <numeric>
typedef long long ll;
using namespace std;

int main(void){
  int n, m, k, i, j;
  cin >> n >> k;
  m = n*(n+1)/2;
  
  vector<ll> a(n), s(m);

  for(i=0;i<n;i++){
    cin >> a[i];
  }

  ll tmp;
  int index = 0;
  for(i=0;i<n;i++){
    tmp = 0;
    for(j=i;j<n;j++){
      tmp += a[j];
      s[index] = tmp;
      index++;
    }
  }

  ll x = 0LL;
  int cnt;
  for(i=40;i>=0;i--){
    cnt = 0;
    tmp = x + (1LL<<i);
    for(j=0;j<m;j++){
      if(ll(tmp&s[j])==tmp) cnt++; 
    }
    if(cnt>=k) x = tmp;
  }

  cout << x << endl;

  return 0;
}
