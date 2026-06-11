#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }

    ll m = 0;
    bool z = false;

    for (ll i = 0; i < n; i++){
        if (a[i] == 0){
            z = true;
        }
        else if (a[i] < 0){
            m++;
        }
    }

    vector<ll> b(n);
    for (ll i = 0; i < n; i++){
        b[i] = abs(a[i]);
    }

    sort(b.begin(), b.end());

    ll ans = 0;

    if (z){
        for (ll i = 0; i < n; i++){
            ans += b[i];
        }
    }
    else{
        if (m%2 == 0){
            for (ll i = 0; i < n; i++){
                ans += b[i];
            }
        }
        else{
            for (ll i = 1; i < n; i++){
                ans += b[i];
            }
            ans -= b[0];
        }
    }

    cout << ans << endl;
}