#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> h(N);
    set<ll> h_set;
    rep(i, N){
        cin >> h[i];
        h_set.insert(h[i]);
    }
    vector<ll> h_v(h_set.begin(), h_set.end());
    h_v.insert(h_v.begin(), 0);

    ll ans = 0;
    for(ll i = h_v.size()-1;i>0;--i){
        bool conti = false;
        rep(j, N){
            if (conti){
                if (h[j] != h_v[i]){
                    conti = false;
                    ans += h_v[i] - h_v[i-1];
                }else{
                    h[j] -= h_v[i] - h_v[i-1];
                }
            }else{
                if (h[j] == h_v[i]){
                    h[j] -= h_v[i] - h_v[i-1];
                    conti = true;
                }
            }
        }
        if (conti){
            ans += h_v[i] - h_v[i-1];
        }
    }

    cout << ans << endl;


    return 0;
}
