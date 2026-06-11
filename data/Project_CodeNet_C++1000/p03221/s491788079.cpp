// #Sazaの1日1AC
#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9+7;
const long long INF = 9e15;
const double PI = 3.14159265358979323846;

//マクロ
//型エイリアス
using ll = int;
using P = pair<long long, long long>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vP = vector<pair<long long, long long>>;
//ショートカット
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, k, n) for (int i = k; i < n; i++) //半開区間
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pb push_back
#define mkp make_pair
//入力
#define vin(v, N) for (long long i = 0; i < N; i++) cin >> v.at(i)
#define lin(n)long long n;cin >> n
#define chin(x)char x;cin >> x;
#define sin(s)string s;cin >> s;
#define vlin(v, N)vector<long long> v(N);for (long long i = 0; i < N; i++)cin >> v.at(i)
#define max(a, b) max((ll)a, (ll)b)
#define min(a, b) min((ll)a, (ll)b)


/////////////////⊂('ω'⊂ )))Σ≡GO!/////////////////
int main(){
  //doubleの桁数
  //std::cout << fixed << setprecision(10);

  lin(N);lin(M);
  vector<string> num(M);
  vector<ll> order(N);
  vector<tuple<ll, ll, ll>> pre(M);
  rep(i,M){
    lin(p);lin(y);
    ll id = i;
    pre[i] = make_tuple(y, p, id);
  }

  sort(all(pre));

  rep(i,M){
    ll y, p, id;
    tie(y, p, id) = pre[i];
    ll ord = order[p] + 1;
    order[p]++;
    num[id] = to_string(ord);
    ll n = 6 - num[id].size();
    rep(j, n) num[id] = '0' + num[id];
    num[id] = to_string(p) + num[id];
    n = 12 - num[id].size();
    rep(j, n) num[id] = '0' + num[id];
  }

  rep(i,M) cout << num[i] << endl;
}