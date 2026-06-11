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
    vector<ll> b(n);
    for (ll i = 0;i < n;i++){
        cin >> b[i];
    }

    vector<ll> d(n);
    for (ll i = 0;i < n;i++){
        d[i] = a[i] - b[i];
    }

    ll sum = 0;
    for (ll i = 0; i < n; i++){
        sum += d[i];
    }
    if (sum < 0){
        cout << -1 << endl;
        return 0;
    }

    ll minus = 0;
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        if (d[i] < 0){
            minus -= d[i];
            ans++;
        }
    }

    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());

    for (ll i = 0; minus > 0; i++){
        minus -= d[i];
        ans++;
    }

    cout << ans << endl;

}