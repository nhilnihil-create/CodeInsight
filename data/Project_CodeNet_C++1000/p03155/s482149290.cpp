#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;

const ll e5 = 1 << 20;
const ll mod = 998244353;
const ll e3 = 1 << 13;
const ll INF = 1ll << 60;

ll h,w,n;

int main(){
  cin >> n >> h >> w;
  cout << (n-h+1)*(n-w+1) << endl;
}
