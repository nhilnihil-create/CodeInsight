#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vector<string> s(n); rep(i,n) cin >> s[i];
  int Xa = 0, bX = 0, bXa = 0;
  int ans = 0;
  rep(i,n){
    if(s[i][0] == 'B' && s[i][(int)s[i].size()-1] == 'A') bXa++;
    else if(s[i][0] == 'B') bX++;
    else if(s[i][(int)s[i].size()-1] == 'A') Xa++;
    rep(j,(int)s[i].size()-1) if(s[i][j]=='A' && s[i][j+1]=='B') ans++;
  }

if(bXa){
  if(Xa+bX != 0) cout << ans+bXa+min(Xa,bX);
  else cout << ans+bXa-1;
} else cout << ans+min(Xa,bX);
  cout << "\n";
  return 0;
}
