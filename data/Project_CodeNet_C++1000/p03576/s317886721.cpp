#include <bits/stdc++.h>
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define int long long
#define double long double
#define PI 3.141592653589793
typedef long long ll;
const int MOD = 1000000007;
const int INF = LLONG_MAX;
const double EPS = 1e-10;
using namespace std;
const pair<int,int> fd[] = {make_pair(1,0),make_pair(-1,0),make_pair(0,1),make_pair(0,-1)}; 

vector<int> divisor(int n){
  vector<int> ret;
  for(int i = 1;i*i <= n;i++){
    if(n%i == 0){
      ret.push_back(i);
      if(i*i != n)ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}
int n,kk;pair<int,int> p[51];
signed main() {
  int ans = INF;
  cin>>n>>kk;rep(i,n)cin>>p[i].first>>p[i].second;
  rep(i,n){
    rep(j,n){
      rep(k,n){
        rep(l,n){
          int xm = p[i].first, xn = p[j].first, ym = p[k].second, yn = p[l].second;
          if(xm < xn)swap(xm,xn);if(ym < yn)swap(ym,yn);
          int cnt = 0;
          rep(m,n){
            if(xn <= p[m].first && p[m].first <= xm && yn <= p[m].second && p[m].second <= ym)cnt++;
          }
          if(cnt >= kk){
            ans = min(ans, (xm-xn)*(ym-yn));
          }
        }
      }
    }
  }
  cout << ans << endl;
}

