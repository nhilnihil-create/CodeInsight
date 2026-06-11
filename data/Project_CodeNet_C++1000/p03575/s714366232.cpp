#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main(){
    ll n,m,p; cin >> n >> m;
    ll ans = 0;
    vector<vector<ll>> a(51);
    vector<vector<bool>> b(51,vector<bool>(51,false));
    vector<ll> x(51),y(51);
    vector<bool> v(51,false);

    rep(i,m){
        cin >> x[i] >> y[i];
        a[x[i]].push_back(y[i]);
        a[y[i]].push_back(x[i]);
        b[x[i]][y[i]] = true;
        b[y[i]][x[i]] = true;
    }

    queue<ll> q;

    rep(i,m){
        b[x[i]][y[i]] = false;
        b[y[i]][x[i]] = false;
        q.push(1);

        while (!q.empty()){
            p = q.front();
            q.pop();

            rep(j,a[p].size()){
                if(b[p][a[p][j]] && !v[a[p][j]]){
                    v[a[p][j]] = true;
                    q.push(a[p][j]);
                }
            }
        }

        for(int j = 1; j <= n; j ++){
            if(!v[j]) {
                ans ++;
                break;
            }
        }
        rep(j,n+1) v[j] = false;

        b[x[i]][y[i]] = true;
        b[y[i]][x[i]] = true;
    }

    cout << ans;
}