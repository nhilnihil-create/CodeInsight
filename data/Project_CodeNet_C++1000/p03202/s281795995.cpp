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

main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = n + 1;
    while (r - l > 1){
        int m = (l + r) >> 1;
        bool fl = 1;
        vector<pair<int, int> > vv;
        for (int i = 1; i < n; i++){
            if (a[i] <= a[i-1]){
                if (m == 1){
                    fl = 0;
                    break;
                }
                int cur = a[i] - 1;
                while (vv.size() && vv.back().fi > cur)
                    vv.pop_back();
                while (cur >= 0 && vv.size() && vv.back().fi == cur && vv.back().se == m)
                    vv.pop_back(), cur--;
                if (cur < 0){
                    fl = 0;
                    break;
                }
                if (vv.empty() || vv.back().fi < cur)
					vv.eb(cur, 2);
				else
					vv.back().se++;
            }
        }
        if (fl)
            r = m;
        else
            l = m;
    }
    cout << r << endl;






}
