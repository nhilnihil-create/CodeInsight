#include<bits/stdc++.h>
#define rep(i,n)  for(ll i=0; i<n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int h,w; cin >> h >> w;
  vector<string> s(h);
  rep(i,h) cin >> s[i];
  vector<vi> cnt(h+2,vi(w+2));
  for(int i = 1; i <= h; i++){
    for(int j = 1; j <= w; j++){
      if(s[i-1][j-1] == '#'){
        cnt[i-1][j-1]++;
        cnt[i-1][j]++;
        cnt[i-1][j+1]++;
        cnt[i][j-1]++;
        cnt[i][j+1]++;
        cnt[i+1][j-1]++;
        cnt[i+1][j]++;
        cnt[i+1][j+1]++;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      if(s[i][j]=='.') cout << cnt[i+1][j+1];
      else cout << "#";
    }
    cout << "\n";
  }
  cout << "\n";
  return 0;
}
