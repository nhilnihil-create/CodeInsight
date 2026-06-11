#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define strall(v) (v).cbegin(),(v).cend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> cost(n+1,0);
  cost[0] = abs(a[0]);
  ll total = cost[0];
  for(int i=1;i<n;i++) {
    cost[i] = abs(a[i] - a[(i-1)]);
    total += (cost[i] + 0LL);
  }
  cost[n] = abs(a[n-1]);
  total += abs(a[n-1]);
  rep(i,n) {
    ll tmp = total,ans = 0;
    if(i==0) {
      //cout << "begin: ";
      tmp-=(cost[0]+cost[1]);
      ans = tmp + abs(a[i+1]);
      cout << ans << endl;
      continue;
    }else if(i == n-1){
      //cout << "end: " ; 
      tmp-=(cost[i]+cost[i+1]);
      ans = tmp + abs(a[i-1]);
      cout << ans << endl;
      continue;
    }
    tmp-=(cost[i]+cost[i+1]);
    tmp+=abs(a[i+1] - a[i-1]);
    cout << tmp << endl;
  }
   
}
