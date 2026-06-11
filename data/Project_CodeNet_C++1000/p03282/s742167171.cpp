#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
using vi = vector<int>;
using vll = vector<ll>;
const ll INF = 1LL<<60;

int main(){
  string s; cin >> s;
  ll k; cin >> k;
  for(int i = 0; i < k; i++){
    if('1' != s[i]){
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}
