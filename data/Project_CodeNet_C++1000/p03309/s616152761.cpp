#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]-=(i+1);
    }

    sort(a.begin(),a.end());
    ll ref=LONG_LONG_MAX;
    ll opt=a[n/2];
    for(int i = opt-11; i < opt+12; i++) {
        ll ans=0;
        for(int j = 0; j < n; j++) {
            ans+=abs(a[j]-i);
        }
        ans=min(ref,ans);
        ref=ans;
    }

    cout << ref << "\n";
    return 0;
}