#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> a(n); rep(i,n) cin >> a[i];

  int Alice = 0,Bob = 0;
  sort(a.begin(),a.end());
  for(int i = n-1;i>=0;i-=2){
    Alice += a[i];
    if(i-1>=0) Bob += a[i-1];
  }
  int ans = Alice-Bob;
  cout << ans << endl;
  
  return 0;
}
