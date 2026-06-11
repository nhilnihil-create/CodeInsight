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
  string s; cin >> s;
  vi b(n+1), w(n+1);
  rep(i,n){
    b[i+1] += b[i];
    if(s[i] == '#') b[i+1]++;
  }
  for(int i = n-1; 0 <= i; i--){
    w[i] += w[i+1];
    if(s[i] == '.') w[i]++;
  }
  int ans = INF;
  rep(i,n) chmin(ans,w[i+1]+b[i]);
  cout << ans;
  cout << "\n";
  return 0;
}
