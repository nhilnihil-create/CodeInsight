#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define repr(i, a, b) for(int i = a; i >= b; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
#define pp pair<ll, pair<ll, ll>> 
#define fi first
#define se second

void print(Vl vec){
    rep(i, 0, sz(vec)){
        if(i) cout << " ";
        cout << vec[i];
    }
    coel;
}

////////////////////////////////////////////////////////


int main() {
    ll n, k; string s;
    cin >> n >> k >> s;
    Vl v;
    if(s[0] == '0') v.push_back(0); // 端に1が0こあると考える
    ll cnt = 1;
    rep(i, 1, n){
        if(s[i]!=s[i-1]){
            v.push_back(cnt);
            cnt = 1;
        }else{
            cnt++;
        }
    }
    v.push_back(cnt);
    if(s[n-1]=='0') v.push_back(0);

    if(sz(v)/2 <= k){
        co(n);
        return 0;
    }

    // print(v);///////////////

    Vl sum(sz(v)+1);
    sum[0] = 0;
    rep(i, 0, sz(v)){
        sum[i+1] = sum[i];
        sum[i+1] += v[i];
    }
    // print(sum);

    ll ans = 0;
    rep(i, 0, sz(v)){
        if(i+2*k+1 >= sz(sum)) break;
        if(i%2 != 0) continue;
        chmax(ans, sum[i+2*k+1]-sum[i]);
    }
    co(ans);

    return 0;
}
