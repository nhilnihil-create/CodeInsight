#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vi x(n); rep(i,n) cin >> x[i];
  ll sum = 0;
  rep(i,k-1) sum += x[i+1]-x[i];
  ll ans = INF;
  rep(i,n-k+1){
    chmin(ans,sum+min(abs(x[i]),abs(x[i+k-1])));
    sum -= x[i+1]-x[i];
    sum += x[i+k]-x[i+k-1];
  }
  cout << ans;
  cout << "\n";
  return 0;
}
