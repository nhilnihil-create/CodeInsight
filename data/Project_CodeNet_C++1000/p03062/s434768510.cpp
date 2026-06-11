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
  int n; cin >> n;
  int minus = 0, zero = 0;
  ll ans = 0;
  int mn = INF;
  rep(i,n){
    int a; cin >> a;
    if(a < 0) minus++;
    if(a == 0) zero++;
    ans += abs(a);
    chmin(mn,abs(a));
  }
  if(zero == 0 && minus % 2 == 1) ans -= mn*2;
  cout << ans;
  cout << "\n";
  return 0;
}
