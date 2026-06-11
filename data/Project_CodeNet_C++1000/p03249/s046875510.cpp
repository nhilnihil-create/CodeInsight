#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double EPS = 1e-15;
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;
const ll MOD1 = 998244353;
//typedef pair<int,int> P;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
//#define mp make_pair

ll dist;
ll dd;
int node;
bool used[100010];
vector<int> G[100010];

void dfs(int n, ll d) {
  used[n] = 1;
  REP(i,G[n].size()) {
    if (used[G[n][i]]) continue;
    dfs(G[n][i], d + 1);
  }
  dd += d;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  //現在のノード数に対応する次のノードまでのsumの変化値
  ll diff[n/2+1] = {};
  for (int i = 1; i <= n / 2; i++) {
    diff[i] = n - i * 2;
  }

  //sumとノード番号の対応
  map<ll,ll> mp;
  //sumを入れるところ
  vector<ll> v;
  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    mp[a] = i+1;
    v.pb(a);
  }
  dist = v[0];
  node = 1;
  sort(v.rbegin(),v.rend());

  //答え
  vector<pair<ll,ll>> ans;

  //最後尾のノードをsetに入れる
  //つながってたら消す
  set<ll> st;

  //予測するため，つぎのノードのsumをnextに入れる
  set<ll> next;
  //前のノードを記録する
  vector<ll> pre[100010];
  //次への変化値を知るため，ノード数をlvに記録する
  map<ll,ll> lv;

  /*****手順*******/
  //現在のノードがnext候補にあるとき
  ////グラフを構築する
  ////前のノードをstから消す
  ////lvを数える

  ////lv++
  ////現在のノードをnextから消す
  ////現在のノードをstに入れる
  ////次のノードをnextに入れる

  //最後にnextに要素があるときは-1
  //nextが一つだけの時はok

  for (ll i = 0; i < n; i++) {
    if (next.count(v[i])) {
      for (int j = 0; j < pre[mp[v[i]]].size(); j++) {
        ans.pb({mp[v[i]], mp[pre[mp[v[i]]][j]]});
        st.erase(pre[mp[v[i]]][j]);
        lv[v[i]] += lv[pre[mp[v[i]]][j]];
      }
    }
    lv[v[i]]++;
    next.erase(v[i]);
    st.insert(v[i]);
    if (!mp.count(v[i] - diff[lv[v[i]]]) && i != n - 1) {
      cout << -1 << endl;
      return 0;
    }
    if (i != n - 1) {
      pre[mp[v[i] - diff[lv[v[i]]]]].pb(v[i]);
      next.insert(v[i] - diff[lv[v[i]]]);
    }
  }

  if (next.size()) {
    cout << -1 << endl;
    return 0;
  }

  REP(i,sz(ans)) {
    G[ans[i].fi].pb(ans[i].se);
    G[ans[i].se].pb(ans[i].fi);
  }


  dfs(1,0);

  if (dist != dd) {
    cout << -1 << endl;
    return 0;
  }

  REP(i,sz(ans)) {
    cout << ans[i].fi << " " << ans[i].se << endl;
  }
  return 0;
}
