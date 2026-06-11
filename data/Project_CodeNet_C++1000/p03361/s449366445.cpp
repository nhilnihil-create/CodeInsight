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
  vector<vector<char>> s(h+2,vector<char>(w+2));
  rep(i,h) rep(j,w) cin >> s[i+1][j+1];

  rep(i,h+1){
    rep(j,w+1){
      if(s[i][j]=='#' && s[i][j+1]!='#' && s[i][j-1]!='#' && s[i-1][j]!='#' && s[i+1][j]!='#'){
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes";
  cout << "\n";
  return 0;
}
