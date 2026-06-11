#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e5 + 5;

ll a[N], cum[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, m;
    cin >> n >> m;
    map<ll, ll>freq;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    freq[0] = 1;
    for(int i = 1; i <= n; i++){
        cum[i] = cum[i - 1] + a[i];
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll kam = cum[i]%m;
        ans += freq[kam];
        freq[kam]++;
    }
    cout << ans;


    return 0;
}
