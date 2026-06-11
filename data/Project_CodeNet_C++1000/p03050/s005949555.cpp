#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

vector<ll> enumerate_num(ll x){
    vector<ll> res;
    for(ll i = 1; i * i <= x; i++){
        if (x % i == 0){
            res.push_back(i);
            if (i * i != x) res.push_back(x / i);
        }
    }
    sort(all(res));
    return res;
}

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    auto res = enumerate_num(n);
    for(int i = 1; i < sz(res); i++){
        ll x = res[i]-1;
        if ((n / x) == (n % x)) ans += x;
    }
    view(ans);
    return 0;
}