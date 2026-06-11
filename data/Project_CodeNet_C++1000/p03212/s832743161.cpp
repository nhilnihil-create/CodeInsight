#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

bool fc(int x){
  bool f3 = false, f5 = false, f7 = false;
  while(x != 0){
    int m = x % 10;
    if(m == 3) f3 = true;
    if(m == 5) f5 = true;
    if(m == 7) f7 = true;
    x /= 10;
  }
  return f3 && f5 && f7;
}

int main(){
  int n;
  cin >> n;
  queue<int> q;
  if(3 <= n) q.push(3);
  if(5 <= n) q.push(5);
  if(7 <= n) q.push(7);
  int ans = 0;
  while(!q.empty()){
    int now = q.front(); q.pop();
    if(fc(now) == true) ans++;
    if((ll)now*10+3 <= n) q.push(now*10+3);
    if((ll)now*10+5 <= n) q.push(now*10+5);
    if((ll)now*10+7 <= n) q.push(now*10+7);
  }
  cout << ans << endl;
  return 0;
}