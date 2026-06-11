#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n;
    cin >> n;

    ll p[n];
    rep(i, 0, n){
        cin >> p[i];
    }

    map<ll, ll> flag;
    ll ans = 0;

    rep(i, 0, n){
        if(flag.count(p[i] - 1)){
            flag[p[i]] = flag[p[i] - 1] + 1;
        }else{
            flag[p[i]] = 1;
        }
        ans = max(ans,flag[p[i]]);
    }

    cout << n - ans << endl;
    return 0;
}

