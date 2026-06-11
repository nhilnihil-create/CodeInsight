#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
const int INF = 1001001001;
const ll mod = 1e9+7;



int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<P>> v(n);
  vector<P> a(m);

  rep(i,m){
    int p1,y1;
    cin>>p1>>y1;
    p1--;
    v[p1].push_back(make_pair(y1,i));
  }
  rep(i,n){
    if (!v[i].empty()){
    sort(v[i].begin(),v[i].end());
    rep(j,v[i].size()){
      int ken=i+1;
      int yn=j+1;
      int ai=v[i][j].second;
      a[ai]=make_pair(ken,yn);
    }
  }
}
rep(i,m){
  std::cout << std::setfill('0') << std::right << std::setw(6) << a[i].first;
  std::cout << std::setfill('0') << std::right << std::setw(6) << a[i].second;
  cout<<endl;


}


}
