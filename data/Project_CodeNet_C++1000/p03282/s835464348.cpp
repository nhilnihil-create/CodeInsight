#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const string EMP = " ";
const ll INF = 1LL<<60;
const ll MOD = 1000000007;

int main(){
  string s; ll k;
  cin >> s >> k;
  for(ll i = 0; i < k; i++){
    if(s[i] != '1'){
      cout << s[i] << endl;
      return 0;
    }
  }
  cout << 1 << endl;
  return 0;
}
