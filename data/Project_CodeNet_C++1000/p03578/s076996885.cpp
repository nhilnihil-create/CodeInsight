#include<bits/stdc++.h>

using namespace std;
using ll = long long int;

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    map<ll,ll> cnt;

    ll n;
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        cnt[x]++;
    }
    cin >> n;
    while(n--) {
        ll x;
        cin >> x;
        if(cnt[x]--==0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
