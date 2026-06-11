#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001001001001;
const ll mod = 1000000007;

int main(){
    int n, m; cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = -INF;
    for(int i = 0; i < (1 << 3); i++){
        vector<ll> sum;
        for(int j = 0; j < n; j++){
            ll tmp = 0;
            for(int k = 0; k < 3; k++){
                if(i & (1 << k)){
                    if(k == 0) tmp += x[j];
                    if(k == 1) tmp += y[j];
                    if(k == 2) tmp += z[j];
                }
                else{
                    if(k == 0) tmp -= x[j];
                    if(k == 1) tmp -= y[j];
                    if(k == 2) tmp -= z[j];
                }
            }
            sum.push_back(tmp);
        }
        sort(sum.rbegin(), sum.rend());
        ll cnt = 0;
        for(int j = 0; j < m; j++){
            cnt += sum[j];
        }   
        ans = max(cnt, ans);
    }
    cout << ans << endl;
}