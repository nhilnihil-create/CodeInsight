#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i); //√n＊√nではない時
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
 ll n,m;
  cin>>n>>m;
  //m約数求める
  ll ans=0;
  vll a=divisor(m);
  for(auto c:a){
    if(c*n<=m)
    chmax(ans,c);
  }
  cout<<ans<<endl;
}