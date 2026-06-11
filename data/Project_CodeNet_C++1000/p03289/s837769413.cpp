#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vii = vector<vi>;
using Pll = pair<ll, ll>;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define F first
#define S second
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  string s;
  cin >> s;
  bool ans = true;
  if(s[0]!='A'){
    ans = false;
  }
  ll count_C = 0;
  for (ll i = 2; i <= sz(s) - 2;i++){
    if(s[i]=='C'){
      count_C++;
    }
  }
  if(count_C!=1){
    ans = false;
  }
  ll count = 0;
  rep(i, sz(s)){
    if(s[i]>='A'&&s[i]<='Z'){
      count++;
    }
  }
  if(count!=2){
    ans = false;
  }
  if(ans){
    print("AC");
  }
  else{
    print("WA");
  }
}
