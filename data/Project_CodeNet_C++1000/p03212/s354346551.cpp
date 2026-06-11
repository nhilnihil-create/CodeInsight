#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int ans=0;
llint n;
void dfs(llint x,int a,int b,int c){
  if(x>n)return;
  if(a&&b&&c)ans++;
  dfs(x*10+3,1,b,c);
  dfs(x*10+5,a,1,c);
  dfs(x*10+7,a,b,1);
}

void solve(){
  cin >> n;
  dfs(0,0,0,0);
  cout << ans << endl;
}

int main(){
  solve();
  return 0;
}
