#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int H, W;
  cin>>H>>W;
  vector<string> A(H);
  for(int i=0;i<H;++i) cin>>A[i];
  queue<tuple<int, int, int> > que;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if(A[i][j]=='#') que.push(make_tuple(i, j, 0));
    }
  }
  tuple<int, int, int> state;
  int x, y, cost;
  int ans = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    x = get<0>(state);
    y = get<1>(state);
    cost = get<2>(state);
    ans = max(ans, cost);
    if(x>0 && A[x-1][y]=='.') {
      A[x-1][y] = '#';
      que.push(make_tuple(x-1, y, cost+1));
    }
    if(x<H-1 && A[x+1][y]=='.') {
      A[x+1][y] = '#';
      que.push(make_tuple(x+1, y, cost+1));
    }
    if(y>0 && A[x][y-1]=='.') {
      A[x][y-1] = '#';
      que.push(make_tuple(x, y-1, cost+1));
    }
    if(y<W-1 && A[x][y+1]=='.') {
      A[x][y+1] = '#';
      que.push(make_tuple(x, y+1, cost+1));
    }
  }
  cout<<ans<<endl;
}

