#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ld long double
int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n;
  cin >> n;
  Graph k(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    k[a].push_back(b);
    k[b].push_back(a);
  }
  vector<int> c(n);
  rep(i,n)cin >> c[i];
  sort(c.begin(),c.end());
  int ans[n];
  rep(i,n)ans[i]=-1;
  int cnt=n-1;
  queue<int> q;
  q.push(0);
  while(q.size()!=0){
    int y=q.front();
    //cout << y << endl;
    q.pop();
    ans[y]=c.at(cnt);
    //cout << y << " " << cnt << " " << ans[y] << endl;
    cnt--;
    for(int o: k[y]){
      if(ans[o]>=0)continue;
      q.push(o);
    }
  }
  int an=0;
  rep(i,n-1)an+=c[i];
  cout << an << endl;
  rep(i,n-1)cout << ans[i] << " ";
  cout << ans[n-1] << endl;
}