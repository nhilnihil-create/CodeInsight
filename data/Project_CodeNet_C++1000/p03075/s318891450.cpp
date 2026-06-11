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
const int MOD = 1000000007;
template<class T> void print(const T& t){ cout << t << endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  vector<ll> a(6);
  rep(i,6){
    cin >> a[i];
  }
  rep(i,5){
    chmin(a[0], a[i]);
  }
  ll b = a[0];
  rep(i, 5){
    chmax(a[0], a[i]);
  }
  ll c = a[0];
  ll d = c - b;
  if(d>a[5]){
    print(":(");
  }
  else{
    print("Yay!");
  }
}