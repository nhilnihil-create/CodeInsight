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
using namespace std;
typedef long long ll;

main(){
    int h, w, n;
    cin >> h >> w >> n;
    vector <int> a(h + 1, w);
    a[h] = 0;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x] = min(a[x], y);
    }
    int maxy = 0;
    for (int i = 1; i < h + 1; i++){
        if (a[i] <= maxy){
            cout << i;
            return 0;
        }
        if (a[i] != maxy + 1) maxy++;
    }

}
