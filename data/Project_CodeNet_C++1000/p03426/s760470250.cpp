#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  int h,w,d;
  cin >> h >> w >> d;
  vector<pp> maze(h*w+1);
  rep(i,h)rep(j,w){
    int a;
    cin >> a;
    maze.at(a) = make_pair(i,j);
  }
  vector<ll> step(h*w+1);
  for(int i=1;i<=h*w;i++){
    if(i <= d) continue;
    step.at(i) = step.at(i-d) + abs(maze.at(i-d).first-maze.at(i).first) + abs(maze.at(i-d).second-maze.at(i).second);
  }
  int q;
  cin >> q;
  rep(i,q){
    int l,r;
    cin >> l >> r;
    ll ans;
    if(l > 0) ans = step.at(r) - step.at(l);
    else ans = step.at(r);
    cout << ans << endl;
  }
  
  return 0;
}



