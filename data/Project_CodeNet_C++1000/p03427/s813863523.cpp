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
  int digit = s.size();
  ll n = stoll(s);
  int ans = 0;
  rep(i,digit){
    int k = n % 10;
    n /= 10;
    if(i != digit-1){
      if(k != 9) n--;
      ans += 9;
    }else{
      ans += k;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
