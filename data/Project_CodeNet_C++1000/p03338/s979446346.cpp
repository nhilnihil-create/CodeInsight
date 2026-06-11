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
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  rep(i,n){
    string x = s.substr(0,i), y = s.substr(i);
    set<char> st1,st2;
    rep(j,x.size()) st1.insert(x[j]);
    rep(j,y.size()) st2.insert(y[j]);

    int cnt = 0;
    for(auto a : st1) if(st2.count(a)) cnt++;
    chmax(ans,cnt);
  }
  cout << ans;
  cout << "\n";
  return 0;
}
