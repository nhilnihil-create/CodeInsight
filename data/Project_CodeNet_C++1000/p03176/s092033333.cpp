#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1e18;

vector<ll> value;
ll N;

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
  //  cout<<"a"<<a<<"b"<<b<<"k"<<k<<"l"<<l<<"r"<<r<<endl;
    if (r <= a || b <= l) return 0; // 区間が被らない場合は INF を返す
    if (a <= l && r <= b){
  //    cout<<"k"<<value[k]<<endl;
          return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
      // に完全に含まれる
    }

    else {
        ll c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        ll c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
    //    cout<<"c1"<<c1<<"c2"<<c2<<endl;
        return max(c1, c2); // 左右の子の値の min を取る
    }
}

int main() {
  ll n;
  cin>>n;
  vector<ll> h(n);
  vector<ll> a(n);
  rep(i,n)cin>>h[i];
  rep(i,n)cin>>a[i];
  N=1;
  while (N<=n)N*=2;
//  cout<<N<<endl;
  value=vector<ll>(2*N-1,0);

  ll dp1[n+1];

  rep(i,n){
    ll now=query(0,h[i],0,0,N);
    update(h[i],now+a[i]);
  //  cout<<h[i]<<"now"<<now<<"na"<<(now+a[i])<<"i"<<i<<endl;
  }
ll ans=0;
ans=query(0,n+1,0,0,N);
cout<<ans;

}




/*
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using ll = long long;
using namespace std;

ll n;
ll h[200200], a[200200], bit[200200];

ll maxi(ll i){
    ll res = 0;
    while(i>0){
        res = max(res,bit[i]);
        i -= i & -i;
    }
    return res;
}
void update(ll i, ll x){
    while(i<=n){
        bit[i] = max(bit[i],x);
        i += i & -i;
    }
}

ll main(){
    cin >> n;
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];

    rep(i,n) update(h[i], a[i] + maxi(h[i]));
    cout << maxi(n) << endl;
    return 0;
}
*/
