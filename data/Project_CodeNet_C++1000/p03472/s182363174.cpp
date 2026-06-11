#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,h; cin >> n >> h;
  vi a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  sort(all(a),greater<int>());
  sort(all(b),greater<int>());
  int sum = 0, ans = 0, i = 0;
  while(sum < h){
    ans++;
    if(a[0] < b[i]){
      sum += b[i];
      i++;
    }else sum += a[0];
  }
  cout << ans;
  cout << "\n";
  return 0;
}
