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
int nxt(int a){
    int r = 1ll;
    int ret = 0;
    while (r <= a){
        r *= 2;
        ret++;
    }
    return r;
}
main(){
    int n;
    cin >> n;
    map <int,int> b;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
            cin >> a[i];
            b[a[i]]++;
    }
    sort(rng(a));
    int ans = 0;
    for (int i = n - 1; i > -1; i--){
            if(b[a[i]] == 0) continue;
        int next_2 = nxt(a[i]);
        int q = next_2 - a[i];
        b[a[i]]--;
        if (b[q] > 0){
            b[q]--;
            ans++;
        }else b[a[i]]++;
    }
    cout << ans;

}
