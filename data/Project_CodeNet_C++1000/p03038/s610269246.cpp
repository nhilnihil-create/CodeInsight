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

    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<pair<ll,ll>> p(m);
    for (ll i = 0;i < m;i++){
        cin >> p[i].second >> p[i].first;
    }

    sort(a.begin(), a.end());
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    ll c = 0;

    for (ll i = 0; i < n; i++){
        if (p[c].second == 0){
            c++;
        }

        if (a[i] < p[c].first){
            a[i] = p[c].first;
            p[c].second--;
        }else{
            break;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ans += a[i];
    }
    cout << ans << endl;
}