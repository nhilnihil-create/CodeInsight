#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
using Graph = vector<vector<int>>;

// 全探索

int main() {
  ll n; cin >> n;
  Vl x(n), y(n), h(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> h[i];

  Rep(cx, 0, 100) Rep(cy, 0, 100){
    bool f = true; ll H;
    int j = 0;
    while(h[j] < 1) j++;
    H = h[j]+abs(cx-x[j])+abs(cy-y[j]);
    
    rep(i, 0, n){
      if(h[i] != max(H-abs(x[i]-cx)-abs(y[i]-cy), 0LL)) f = false;
    }
    if(f){
      cout << cx << " " << cy << " " << H << endl;
    }
  }

  return 0;
}
