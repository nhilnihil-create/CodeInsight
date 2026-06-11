#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  vector<int> a(3); rep(i,3) cin >> a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  
  int ans = a[0]*10+a[1]+a[2];
  cout << ans << endl;
  
  return 0;
}
