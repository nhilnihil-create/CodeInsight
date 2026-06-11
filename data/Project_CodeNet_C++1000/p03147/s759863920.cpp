#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll v_max(vector<ll> x){
    
    ll n = x.size();
    sort(x.begin(), x.end());
    return x[n-1];

    //vector内の最大値を出力
    //入力:vector<ll>
    //出力:ll

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> h(n);
    for (ll i = 0;i < n;i++){
        cin >> h[i];
    }

    ll ans = 0;

    while (true){
        if (v_max(h) == 0){
            break;
        }
        ll i = 0;
        while (i < n){
            if (h[i] == 0){
                i++;
            }
            else{
                ans++;
                while (i < n && h[i] > 0){
                    h[i]--;
                    i++;
                }
            }
        }
    }

    cout << ans << endl;
        
}