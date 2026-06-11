    #include <bits/stdc++.h>
    #define ll long long
    using namespace std;
    const int N = 2e5 + 5, mod = 1e9 + 7;
     
    ll m[N];
     
    int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        for(int i = 1; i <= n; i++) m[i % k]++;
        ans = m[0] * m[0] * m[0];
        if(k % 2 == 0) ans += m[k >> 1 ] * m[k >> 1] * m[k >> 1];
        cout << ans;
     
        return 0;
    }