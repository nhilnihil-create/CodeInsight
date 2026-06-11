#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")

#define ll long long
#define pb push_back
#define fr first
#define sc second
#define in freopen("input.txt", "r" , stdin)
#define out freopen("snakes.out", "w", stdout)
using namespace std;

ll n;
ll a[100005];
int main(){
    //in;
    //out;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    ll p = 0;

    for (int i = 1; i <= n; i++) {
        ans += abs(p - a[i]);
        p = a[i];
    }
    ans += abs (a[n] - 0);
    cout << ans - abs (0 - a[1]) - abs (a[2] - a[1]) + abs (0 - a[2]) << " ";

    for (int i = 2; i < n; i++) {
        cout << ans - abs (a[i] - a[i-1])  - abs (a[i] - a[i+1])  + abs (a[i+1] - a[i-1])<< " ";
    }

    cout << ans - abs(a[n-1] - a[n]) - abs (0 - a[n]) + abs (a[n-1] - 0) ;
 }
