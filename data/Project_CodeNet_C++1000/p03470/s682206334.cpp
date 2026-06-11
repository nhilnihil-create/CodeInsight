#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n; cin >> n;
  vector<int> d(n); rep(i,n) cin >> d[i];

  int ans = 1;
  sort(d.begin(),d.end());
  int now=d[n-1];
  for(int i = n-2;i>=0;--i)
    if(d[i]<now){
      now = d[i];
      ans++;
    }
  
  cout << ans << endl;
  
  return 0;
}
