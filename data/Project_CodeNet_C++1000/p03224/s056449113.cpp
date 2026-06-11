#include <bits/stdc++.h>
#include <numeric>

typedef long long int ll;
typedef unsigned long long int ull;
#define rep(i,n) for(auto i=0;i<(n);i++)

using namespace std;


void solve(ll vn){
    set<ll> g[vn];
    ll s = 1;

    rep(src, vn){
        for(ll to = src+1; to < vn; to++){
            g[src].insert(s);
            g[to].insert(s);
            s++;
        }
    }

    rep(src, vn){
        cout << vn-1;
        for(auto e : g[src]){
            cout << " " << e;
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
   
    for(ll vn = 1; vn <= 450; vn++){
        ll en = vn*(vn-1)/2;
        if(en == n){
            cout << "Yes" << endl;
            cout << vn << endl;
            solve(vn);
            return 0;
        }
    }

    cout << "No" << endl;


    return 0;
}

