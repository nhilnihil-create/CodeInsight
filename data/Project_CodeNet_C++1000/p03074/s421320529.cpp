#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll n,k; cin >> n >> k;
  if(k>=n){
    cout << n;
    return 0;
  }
  string s; cin >> s;
  queue<ll> q;
  q.push(0);
  char prev='1';
  ll num_1=0;
  ll num_0=0;
  vector<ll> v;
  rep(i,n){
    char cur = s[i];
    if(i>0&&prev!=cur&&cur=='1'){
      q.push(num_1+num_0);
      num_1=0;
      num_0=0;
    }
    if(prev!=cur&&cur=='0'){
      v.push_back(i);
    }
    if(cur=='1'){
      num_1++;
    }else{
      num_0++;     
    }
    prev=cur;
  }
  q.push(num_1+num_0);
  v.push_back(n);
  if(v.size()<=k){
    cout << n;
    return 0;
  }
  ll ans=0;
  ll ruiseki=0;
  for(ll i=k; i<v.size(); i++){
    ruiseki+=q.front();
    q.pop();
    ans=max(ans,v[i]-ruiseki);
  }
  cout << ans << endl;
  return 0;
}


