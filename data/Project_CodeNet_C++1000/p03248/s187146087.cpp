#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  string s;
  cin >> s;
  ll n=s.size();
  if(s[0]!='1'||s[n-1]!='0') {
    cout << -1 << "\n";
    return 0;
  }
  for(ll i=0;i<n&&n-2-i>=0;i++) {
    if(s[i]!=s[n-2-i]) {
      cout << -1 << "\n";
      return 0;
    }
  }
  queue<ll> q;
  for(ll i=0;i<n;i++) {
    if(s[i]=='1'||i==n-1) {
      while(q.size()) {
        cout << q.front()+1 << " " << i+1 << "\n";
        q.pop();
      }
    }
    q.push(i);
  }
}