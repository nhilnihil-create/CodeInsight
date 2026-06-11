#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

int main(){
  int h, w, d;
  cin >> h >> w >> d;
  vector<int> px(h*w + 1), py(h*w + 1);
  rep(i, h) rep(j, w) {
    int a;
    cin >> a;
    px[a] = i;
    py[a] = j;
  }
  vector<int> sum(h * w + 1);
  for(int i = d + 1; i <= h * w; ++i){
    sum[i] = sum[i - d] + abs(px[i] - px[i - d]) + abs(py[i] - py[i - d]);
  }
  int q;
  cin >> q;
  rep(i, q){
    int l, r;
    ll ans;
    cin >> l >> r;
    ans = sum[r] - sum[l];
    cout << ans << endl;
  }
}