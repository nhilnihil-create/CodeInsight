#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
        vec[i] -= (i + 1);
    }
    sort(all(vec));
    ll len_vec = vec.size();
    if (len_vec % 2 == 1){
        ll b = vec[len_vec / 2];
        ll ans = 0;
        rep(i,N){
            ans += max(vec[i] - b, b - vec[i]);
        }
        cout << ans << endl;
    }
    else{
        ll a = vec[len_vec / 2];
        ll b = vec[(len_vec / 2) - 1];
        if ((a + b) % 2 == 0){
            ll c = (a + b)/ 2;
            ll ans = 0;
            rep(i,N){
                ans += max(vec[i] - c, c - vec[i]);
            }
            cout << ans << endl;
        }
        else{
            ll c = (a + b + 1) / 2;
            ll d = (a + b - 1) / 2;
            ll ans_c = 0;
            ll ans_d = 0;
            rep(i,N){
                ans_c += max(vec[i] - c, c - vec[i]);
                ans_d += max(vec[i] - d, d - vec[i]);
            }
            cout << min(ans_c, ans_d) << endl;
        }
    }
}
