#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

bool in_range(int p, int x, int y){
    if (x > y) swap(x, y);
    return x <= p && p <= y;
}

int main(){
    int n, K;
    cin >> n >> K;
    vector<ll> x(n), y(n);
    rep(i, n)
        cin >> x[i] >> y[i];
    ll ans = 4e18;
    rep(i, n)rep(k, n){
        for(int j = i; j < n; j++){
            for(int l = k; l < n; l++){
                int res = 0;
                rep(m, n){
                    if (in_range(x[m], x[i], x[j])&&
                    in_range(y[m], y[k], y[l]))
                        res++;
                }
                if (res >= K) 
                    ans = min(ans, abs((x[j] - x[i]) * (y[l] - y[k])));
            }
        }
    }
    cout << max(ans, 1ll) << endl;
}