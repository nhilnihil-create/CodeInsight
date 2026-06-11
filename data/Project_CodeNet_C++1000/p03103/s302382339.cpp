#include <bits/stdc++.h>
#define rep(i, e, n) for (int i = e; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const ll inf=1000000000007;

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> a(n);
  rep(i,0,n){
    int cost, book;
    cin >> cost >> book;
    a[i].first=cost;
    a[i].second=book;
  }
  sort(a.begin(),a.end());
  ll ans=0;
  rep(i,0,n){
    if(a[i].second<m){
      ans+=(ll)a[i].first*a[i].second;
      m-=a[i].second;
    }
    else{
      ans+= (ll)a[i].first*m;
      cout << ans << endl;
      return 0;
    }
//    cout << ans << ' ' << m << endl;
  }
  return 0;
}