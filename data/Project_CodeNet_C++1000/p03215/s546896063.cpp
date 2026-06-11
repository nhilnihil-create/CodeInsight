#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    ll a[n];
    ll sum[n+1] = {};
    rep(i,n) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    vector<ll> v;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            v.push_back(sum[j]-sum[i-1]);
        }
    }
    ll m = sum[n];
    int c = 0;
    while(m != 0){
        c++;
        m /= 2;
    }
    ll ans = 0;
    vector<bool> use(v.size(), true);
    for(int i = c; i >= 0; i--){
        int t = 0;
        rep(j,v.size()){
            if((((ll)1 << i) & v[j]) && use[j]) t++;
        }
        if(t >= k){
            ans += ((ll)1 << i);
            rep(j,v.size()){
                if(!(((ll)1 << i) & v[j])) use[j] = false;
            }
        }
    }
    cout << ans << endl;
    return 0;
}