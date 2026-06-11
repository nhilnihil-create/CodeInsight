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
  ll a, b, c,x;
  cin >> a >> b >> c>>x;
  ll count = 0;
  rep(i,a+1){
    rep(j,b+1){
      rep(k,c+1){
        ll sum = 500 * i + 100 * j + 50 * k;
        if(sum==x){
          count++;
        }
      }
    }
  }
  print(count);
}
