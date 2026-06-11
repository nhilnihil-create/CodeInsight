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
  string s; cin >> s;
  ll k; cin >> k;
  int num = min(k,(ll)s.size());
  rep(i,num) if('2' <= s[i]){
    cout << s[i];
    return 0;
  }
  cout << 1;
  cout << "\n";
  return 0;
}
