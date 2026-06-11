#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
#define sz(x) ((int) x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef vector<ll> vi;
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll x, y, z;
  if (a >= b){
    x = a - b;
  }
  else if(a<b){
    x = b - a;
  }
  if(b>=c){
    y = b - c;
  }
  else if(b<c){
    y = c - b;
  }
  if(a>=c){
    z = a - c;
  }
  else if(a<c){
    z = c - a;
  }
  bool ans = false;
  if(z<=d){
    ans = true;
  }
  else if(z>d){
    if(y<=d&& x<=d){
      ans = true;
    }
  }
  if(ans){
    print("Yes");
  }
  else{
    print("No");
  }
}