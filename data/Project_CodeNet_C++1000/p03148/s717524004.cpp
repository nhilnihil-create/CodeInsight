#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

const long long INF = 1LL<<40;

int main(void){
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> s(n);
    rep(i, 0, n){
        ll t, d;
        cin >> t >> d;
        --t;
        s[t].push_back(d);
    }

    for(auto &v: s){
        sort(v.begin(), v.end(), greater<ll>());
        if(v.empty()) v.push_back(-INF);
    }

    sort(s.begin(), s.end(), [&](vector<ll> a, vector<ll> b){return a[0] > b[0];});

    ll cur = 0;
    priority_queue<ll> que;
    rep(i, 0, k){
        cur += s[i][0];
        rep(j, 1, s[i].size())
            que.push(s[i][j]);
    }

    rep(i, k, n){
        rep(j, 0, s[i].size()) que.push(s[i][j]);
    }

    ll res =  cur + k * k;
    rrep(x, k-1, 1){
        ll v = s[x][0];
        ll w = que.top();
            que.pop();
            cur += w;
            que.push(v);
            cur -= v;
        res = max(res, cur + x*x);
    }
    cout << res << endl;
}
