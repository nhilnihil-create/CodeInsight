#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n, m;
  cin >> n >> m;
  vector<P> a;
  for(int i=0; i<n; i++){
    int A,B; cin >> A >> B;
    a.push_back(make_pair(A,B));
  }
  sort(a.begin(), a.end());
  ll ans = 0LL;
  for(int i=0; i<n; i++){
    if(m<=a[i].second){
      ans += m*a[i].first;
      break;
    }
    ans += a[i].first*a[i].second;
    m -= a[i].second;
  }
  cout << ans << endl;
  return 0;
}
