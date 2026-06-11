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
  ll n;
  string s;
  cin >> n >> s;
  map<char,ll> cnt;
  for(ll i=0;i<n;i++) cnt[s[i]]++;
  if(cnt['R']>cnt['B']) cout << "Yes" << endl;
  else cout << "No" << endl;
}