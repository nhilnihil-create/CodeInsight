#include <bits/stdc++.h>
using namespace std;
#define arep(i, x, n) for (int i = int(x); i < (int)(n); i++)
#define rep(i, n) for (long long i = 0; i < n; ++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9 + 7
using ll = long long;

int main(){
    ll n;
    ll x;

    cin >> n >> x;

    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    ll cnt = 0;
    rep(i, n){
        x -= a[i];

        if(x < 0){
            break;
        }else{
            cnt++;
        }
    }

    if(x > 0){
        cnt = cnt - 1;
    }

    cout << cnt << endl;
}