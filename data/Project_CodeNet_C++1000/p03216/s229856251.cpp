#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long int
#define pb push_back
#define fi first
#define se second
#define fr(i, a, b) for(int i = a; i <= b; i++)
#define all(x) x.begin(), x.end()
#define IO ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define pii pair<int,int>
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double f80;
#ifndef LOCAL
#define endl '\n'
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}
const int N = 1e6 + 5;
string s;
int cnt[N], pre[N], val[N], preval[N];
void solve(){
    int n;
    cin >> n;
    cin >> s;
    s = "0" + s;
    for(int i = n; i >= 1; i--){
        pre[i] = pre[i + 1] + (s[i] == 'M');
        if(s[i] == 'D'){
            val[i] = pre[i];
        }
        cnt[i] = cnt[i + 1] + (s[i] == 'D');
    }
    for(int i = n; i >= 1; i--){
        preval[i] = preval[i + 1] + val[i];
    }
    int q;
    cin >> q;
    while(q--){
        int ans = 0;
        int k;
        cin >> k;
        fr(i, 1, n){
            if(s[i] == 'C'){
                int j = max((int)1, i - k + 1);
                int vall = preval[j] - (cnt[j] - cnt[i]) * pre[i] - preval[i];
                ans += vall;
            }
        }
        cout << ans << endl;
    }
}
signed main()
{
    IO;
    #ifdef LOCAL
        freopen("inp.txt", "r", stdin);
        // freopen("out.txt", "w", stdout);
    #endif
    clock_t clk = clock();
    int t = 1;
    // cin >> t;
    fr(i, 1, t){
        solve();
    }
    cerr << endl << setprecision(10) << fixed << (double)(clock() - clk) / CLOCKS_PER_SEC;
    return 0;
};