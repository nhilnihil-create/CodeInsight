/*
гонфлад
*/
#pragma ARCENIY_KIRILLOV_UVIDEL_KROKODILOV
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int binpow(int a, int n){
    if (n == 0)
        return 1ll;
    if (n%2 == 0){
        int q = binpow(a, n / 2);
        return (q * q)%mod;
    }else
        return (a * binpow(a, n - 1))%mod;
}
main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> obr(n + 1);
    for (int i = 1; i <= n; i++){
        obr[i] = binpow(i, mod - 2);
    }
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; i++){
        prefix[i] = (prefix[i - 1] + obr[i]) % mod;
    }
    int ans = 0;
    int ce;
    for (int i = 0; i < n; i++){
        ce = (((prefix[i + 1] + prefix[n - i] - 1)% mod) * a[i])%mod;
        ans = (ans + ce)%mod;
    }
    for (int i = 2; i <= n; i++){
        ans = (ans * i)%mod;
    }
    cout << ans;
}
