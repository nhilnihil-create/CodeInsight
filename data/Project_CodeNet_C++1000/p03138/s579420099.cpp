#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;


int main(void){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);

    ll dig = 42;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<int> num0(dig);
    vector<int> num1(dig);

    for(int d = 0; d < dig; d++){
        for(int i = 0; i < n; i++){
            if((a[i] >> d) & 1LL) num1[d]++;
            else num0[d]++;
        }
    }

    ll x = 0;
    for(int d = dig; d >= 0; d--){
        if((num1[d] < num0[d]) && (x + (1LL << d) <= k)){
            x += (1LL << d);
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (x ^ a[i]);
    }
    cout << ans << endl;
    return 0;
}