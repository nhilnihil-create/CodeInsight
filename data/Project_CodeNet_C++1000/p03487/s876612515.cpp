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
  map<int,int> mp;
  rep(i,n){
    int a; cin >> a;
    mp[a]++;
  }
  int ans = 0;
  for(auto x : mp){
    if(x.first <= x.second) ans += x.second-x.first;
    else ans += x.second;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
