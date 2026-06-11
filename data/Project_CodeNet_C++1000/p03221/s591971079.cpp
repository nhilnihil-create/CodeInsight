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

int digit(int n){
  int cnt = 0;
  while(0 < n){
    cnt++;
    n /= 10;
  }
  return cnt;
}
void push_zero(int n){
  int cnt = 6-digit(n);
  rep(i,cnt) cout << 0;
  cout << n;
}
int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vi p(m),y(m);
  map<int,map<int,int>> mp;
  rep(i,m){
    cin >> p[i] >> y[i];
    mp[p[i]][y[i]];
  }
  for(auto &x : mp){
    int cnt = 1;
    for(auto &y : x.second) y.second = cnt++;
  }
  rep(i,m){
    push_zero(p[i]);
    push_zero(mp[p[i]][y[i]]);
    cout << endl;
  }
  cout << "\n";
  return 0;
}
