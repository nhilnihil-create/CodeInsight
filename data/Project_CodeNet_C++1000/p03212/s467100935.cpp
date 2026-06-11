#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

bool check357(ll x){
    bool c3 = false, c5 = false, c7 = false;
    while(x != 0){
        if(x%10 == 3) c3 = true;
        else if(x%10 == 5) c5 = true;
        else if(x%10 == 7) c7 = true;
        x /= 10;
    }
    return c3 & c5 & c7;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll n; cin >> n;
    vi semi357;
    queue<ll> que; que.push(0);

    while(!que.empty()){
        ll f = que.front(); que.pop();
        if(f > 1000000000 || f > n) break;
        semi357.push_back(f);
        que.push(f*10+3);
        que.push(f*10+5);
        que.push(f*10+7);
    }
    ll ans = 0;
    for(auto p: semi357) if(check357(p)) ans++;
    cout << ans << endl;
}