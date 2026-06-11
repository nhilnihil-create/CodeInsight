#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

int main(){
    ll n,k;
    cin >> n >> k;
    ll sum = min(n,k);
    ll v[n+10];
    ll kotae;
    ll ans = -1;
    for(int i = 0; i < n; i++){
        ll temp;
        cin >> temp;
        v[i] = temp;
    }
    for(int i = 0; i <= sum; i++){
        for(int j = 0; j <= sum - i; j++){
            kotae = 0;
            vector<ll> minus;
            for(int k = 0; k < i; k++){
                kotae += v[k];
                if(v[k] < 0){
                    minus.push_back(v[k]);
                }
            }
            for(int k = n-1; k >= n-j;k--){
                kotae += v[k];
                if(v[k] < 0){
                    minus.push_back(v[k]);
                }
            }
            sort(minus.begin(),minus.end());
            ll hoge = minus.size();
            ll dokomade = min(k - i - j,hoge);
            for(int k = 0; k < dokomade; k++){
                kotae -= minus[k];
            }
            ans = max(ans,kotae);

        }
    }

    cout << ans << endl;
}