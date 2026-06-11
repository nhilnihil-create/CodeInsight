#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <ll> a;

ll calc(int l, int r){
    return a[r] - (l <= 0 ? 0 : a[l - 1]);
}
ll calc(int l, int i, int r){
    return abs(calc(l, i) - calc(i + 1, r));
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    for(int i = 1 ; i < n ; i++){
        a[i] += a[i - 1];
    }
    int l = 0, r = 2;
    ll ans = 1e18;
    for(int i = 1 ; i < n - 2 ; i++){
        r = max(r, i + 1);
        while(l + 1 < i && calc(0, l, i) > calc(0, l + 1, i)) l++;
        while(r + 1 < n && calc(i + 1, r, n - 1) > calc(i + 1, r + 1, n - 1)) r++;
        ll mn = min(min(calc(0, l), calc(l + 1, i)), min(calc(i + 1, r), calc(r + 1, n - 1)));
        ll mx = max(max(calc(0, l), calc(l + 1, i)), max(calc(i + 1, r), calc(r + 1, n - 1)));
        ans = min(ans, mx - mn);
    }
    cout << ans << endl;
}
