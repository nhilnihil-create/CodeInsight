#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  ll ans;
  if (b - a <= 2 || k - a <= 0) { // ビスケットを交換しない場合
    ans = k + 1;    
  } else {         // ビスケットを交換する場合
    // ビスケットの数を最初にAにしておけば、あとはビスケットを叩く操作は必要ない
    // (ビスケットを叩くよりも交換したほうがたくさん増える)
    ans = a;      
    k -= a - 1;

    // (b - a) はビスケットの交換を行ったあとの差分
    // (k / 2) はビスケットA枚 -> 1円 -> ビスケットBとなるので、これはk / 2回操作可能
    ans += (b - a) * (k / 2); 
    if (k % 2 == 1) ans++;  // 奇数のときは１回操作が余る
  }

  cout << ans << endl;
}