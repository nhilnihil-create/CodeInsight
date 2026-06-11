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

int main() {
  int n=900000;
    bitset<1000000> is_prime(0); // 十分大きなサイズを確保します (ふるいの容量は1000000)
    for (int i = 2; i <= n; ++i) is_prime.set(i); // とりあえず全部ふるいに入れます( 000000000..001111111111111111...111111100)
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) { // 素数 i を発見したら
            for (int j = i * 2; j <= n; j += i) {
                is_prime.reset(j); // i の倍数をふるい落とす
            }
        }
    }
  int q;
  cin>>q;
  int cnt[110000];//i番目までで2017数が何個あるか
  rep(i,0,110000){
    cnt[i]=0;
  }
  rep(i,3,110000){
    cnt[i]=cnt[i-1];
    if(is_prime[i]&&is_prime[(i+1)/2]) cnt[i]++;
  }
  rep(i,0,q){
   int r,l; 
    cin>>l>>r;
    cout<<cnt[r]-cnt[l-1]<<endl;
  }
}



