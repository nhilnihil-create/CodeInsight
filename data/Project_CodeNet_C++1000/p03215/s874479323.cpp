#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, k;
    cin >> n >> k;

    ll a[n];
    rep(i, 0, n){
        cin >> a[i];
    }

    ll s[n + 1];
    s[0] = 0;
    rep(i, 1, n + 1){
        s[i] = s[i - 1] + a[i - 1];
    }

    ll c[(n * (n + 1)) / 2];
    ll count = 0;
    rep(i, 1, n + 1){
        rep(j, i, n + 1){
            c[count] = s[j] - s[i - 1];
            count++;
        }
    }


    ll ans = 0;
    rrep(i, 40, 0){
        ll count = 0;
        rep(j, 0, (n * (n + 1)) / 2){
            if(((ans | (1LL << i)) & c[j]) == (ans | (1LL << i))){
                count++;
            }
        }
        if(count >= k){
            ans |= (1LL << i);
        }

    }


    cout << ans << endl;
    return 0;

}
