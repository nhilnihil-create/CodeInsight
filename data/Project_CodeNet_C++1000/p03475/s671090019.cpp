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
    vector<ll> c(n-1);
    vector<ll> s(n-1);
    vector<ll> f(n-1);
    for (ll i = 0;i < n-1;i++){
        cin >> c[i] >> s[i] >> f[i];
    }

    vector<ll> ans(505,0);

    for (ll i = 0; i < n; i++){
        for (ll j = i; j < n-1; j++){
            if (s[j] >= ans[i]){
                ans[i] = s[j] + c[j];
            }
            else{
                ll x = (ans[i] + f[j] -1)/f[j];
                ans[i] = f[j]*x + c[j];
            }
        }
    }

    for (ll i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}