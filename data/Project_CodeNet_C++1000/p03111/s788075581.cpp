#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int n, a, b, c;
vector<int> abc;
vector<int> vec;
ll ans = INF;

int check(ll st) {
  vector<int> r(3, 0);
  vector<int> cost(3, 0);
  int cnt = 0;
  while(st) {
    if(st % 10 != 4) {
      int idx = st % 10 - 1;
      if (r[idx] != 0) {
        cost[idx] += 10;
      }
      r[idx] += vec[n-1-cnt];
    };
    st /= 10;
    cnt++;
  }
  int tmp = 0;
  rep(i, 3) {
    if (r[i] == 0) {
      return -1;
    }
    tmp += cost[i] + abs(r[i] - abc[i]);
  }
  return tmp;
}

void dfs(ll st, int cnt) {
  if (cnt == n) {
    int tmp = check(st);
    if (tmp != -1) {
      ans = min(ans, (ll)tmp);
    }
    return;
  }
  reps(i,1,5) {
    ll nxt = st * 10 + i;
    dfs(nxt, cnt+1);
  }
  return;
} 

int main()
{
  cin >> n >> a >> b >> c;
  abc.push_back(a);
  abc.push_back(b);
  abc.push_back(c);
  vec.resize(n, 0);
  rep(i,n) cin >> vec[i];
  dfs(0, 0);
  cout << ans << endl;
  
  return 0;
}