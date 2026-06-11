#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;


  if(s.length() == 26){

    int ind = -1;
    for(int i = 25; i > 0; i--){
      if(s[i] > s[i-1]){
        ind = i;
        break;
      }
    }
    if(ind==-1){
      cout << -1 << endl;
      return 0;
    }

    int num = 30;
    for(int i = ind; i < 26; i++){
      if(s[i] > s[ind-1]){
        chmin(num, int(s[i]-'a'));
      }
    }

    string ans;
    ans = s.substr(0, ind-1) + char(num+'a');

    cout << ans << endl;

  }else{

    // 出ていない文字を付け加える
    set<int> moji;

    rep(i, s.length()){
      moji.insert(int(s[i]-'a'));
    }

    rep(i, 26){
      if(moji.find(i) == moji.end()){
        s += char(i + 'a');
        break;
      }
    }

    cout << s << endl;
  }


  return 0;
}
