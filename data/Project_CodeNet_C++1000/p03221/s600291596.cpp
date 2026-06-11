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
    cout << setw(6) << setfill('0') << p[i];
    cout << setw(6) << setfill('0') << mp[p[i]][y[i]];
    cout << endl;
  }
  cout << "\n";
  return 0;
}
