#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<int, int> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

vector<ll> solve(ll a){
    ll tmp = a;
    vector<ll> b(21,0);
    ll i = 0;
    while(tmp>0){
        if(tmp&1){
            b[i] = 1;
        }else{
            b[i] = 0;
        }
        tmp/=2;
        i ++;
    }

    return b;
}

int main(){

    ll n; cin >> n;
    vector<ll> a(n+5);
    rep(i,n) cin >> a[i];

    ll right = 0;
    ll ans = 0;
    vector<ll> s(21,0);
    vector<ll> b(21);

    for(ll left = 0; left < n; left++){
        // cout << "left " << left << endl;
        bool ok = true;
        while(right < n && ok){
            b  = solve(a[right]);
            // cout << "right " << right<< endl;
            for(ll i = 0; i < 21; i++){
                if(s[i]+b[i] == 2){
                    ok = false;
                }
            }

            if(ok){
                for(ll i = 0; i < 21; i++){
                    s[i] += b[i];
                }
                right ++;
            }
        }

        if(right==left){
            right++;
        }else{
            ans += right - left - 1;
            b = solve(a[left]);
            for(ll i = 0; i < 21; i++){
                s[i] -= b[i];
            }
            // rep(i,21)cout << s[20-i];
            // cout << endl;

        }
        // cout << ans << endl;
    }
    // cout << ans << endl;

    cout << ans + n << endl;



    return 0;
}