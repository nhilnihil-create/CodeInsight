#include<bits/stdc++.h>
#define rep(i,n) for(ll i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  vector<ll> cnt(5);
  rep(i,n){
    string s; cin >> s;
    if(s[0]=='M') cnt[0]++;
    if(s[0]=='A') cnt[1]++;
    if(s[0]=='R') cnt[2]++;
    if(s[0]=='C') cnt[3]++;
    if(s[0]=='H') cnt[4]++;
  }

  ll ans = 0;
  for(int i = 0; i < 3; i++){
    for(int j = i+1; j < 4; j++){
      for(int k = j+1; k < 5; k++){
        ans += cnt[i]*cnt[j]*cnt[k];
      }
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
