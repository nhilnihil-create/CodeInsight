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
    vector<ll> v(n);
    for (ll i = 0;i < n;i++){
        cin >> v[i];
    }

    vector<pair<ll,ll>> even(100005);
    vector<pair<ll,ll>> odd(100005);

    for (ll i = 0; i < 100005; i++){
        even[i] = make_pair(0,i);
        odd[i] = make_pair(0,i);
    }

    for (ll i = 0; i < n; i++){
        if (i%2 == 0){
            even[v[i]].first++;
        }
        else{
            odd[v[i]].first++;
        }
    }

    sort(even.begin(), even.end());
    reverse(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    reverse(odd.begin(), odd.end());

    ll ans = 0;
    if (even[0].second != odd[0].second){
        ans = n - even[0].first - odd[0].first;
    }
    else{
        ans = min((n - even[0].first - odd[1].first),(n - even[1].first - odd[0].first));
    }

    cout << ans << endl;

}