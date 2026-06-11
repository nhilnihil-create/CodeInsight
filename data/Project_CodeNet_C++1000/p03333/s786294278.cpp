#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

#define max(x, y) ((x)>(y)?(x):(y))
#define min(x, y) ((x)<(y)?(x):(y))

Int move(Int l, Int r, Int x){
  return max(l, min(x, r));
}

Int n;
Int l[108000], r[108000];

Int solve(){
  priority_queue<P, vector<P>, greater<P> > rpq;
  priority_queue<P> lpq;
  for(int i = 0;i < n;i++){
    lpq.push(P(l[i], i));
    rpq.push(P(r[i], i));
  }
  Int res = 0;
  Int now = 0;
  Int nxtlr = 0;
  vector<int> used(n, 0);

  for(int i = 0;i < n;i++){
    Int ind;
    if(nxtlr == 0){
      while(used[lpq.top().second])lpq.pop();
      ind = lpq.top().second;lpq.pop();
    }
    else{
      while(used[rpq.top().second])rpq.pop();
      ind = rpq.top().second;rpq.pop();
    }
    Int nxt = move(l[ind], r[ind], now);
    //    cout << ind << " " << nxt << endl;
    used[ind] = true;
    res += abs(now - nxt);
    now = nxt;
    nxtlr ^= 1;
  }
  res += abs(now- 0);
  return res;  
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> l[i] >> r[i];
  }

  Int res = solve();
  for(int i = 0;i < n;i++){
    l[i] *= -1;
    r[i] *= -1;
    swap(l[i], r[i]);
  }

  res = max(res, solve());

  cout << res << endl; 
  return 0;
}