
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int INF=1001001001;

vector<ll> value; // ノードの値を持つ配列
ll N;             // 葉の数

void update(ll i, ll x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i] = x;
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = max(value[i * 2 + 1],
                       value[i * 2 + 2]); // 左右の子の min を計算しなおす
    }
}

ll query(ll a, ll b, ll k, ll l, ll r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return 0; // 区間が被らない場合は INF を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
    // に完全に含まれる
    else {
        ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
        return max(c1, c2); // 左右の子の値の min を取る
    }
}



int dp[200005];

int main(){
  ll n;
  cin>>n;
  vector<ll> h(n);
  vector<ll> a(n);
  rep(i,n)cin>>h[i];
  rep(i,n)cin>>a[i];
  N=1;
  while(N<=n)N*=2;
  value = vector<ll>(2 * N - 1, 0);
//  dp[0]=0;

  rep(i,n){
    ll temp=query(0,h[i],0,0,N);
//    cout<<temp<<endl;
    update(h[i],temp+a[i]);
  //  cout<<temp+a[i]<<endl;
  }
cout<<query(0,n+1,0,0,N);

}
