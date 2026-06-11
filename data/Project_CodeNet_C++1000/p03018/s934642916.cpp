#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef pair <ll ,ll> pll;
typedef pair <int ,int> pii;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define print(a) {for (auto iiiiiiiiii : a) cout << iiiiiiiiii << ' '; cout << '\n';}
#define fi first
#define se second
#define all(x) (x).begin() , (x).end()

ll next() {ll x; cin >> x; return x;}

const ll inf = 1e18 , mod = 998244353;
const int intf = 2e9 , maxn = 1e5;
const double PI = 3.141592653589 , eps = 1e-8;


void solve(){
    string s; cin >> s;
    int cnta = 0 , n = s.size();
    ll ans = 0;
    for (int i = 0 ; i < n; i ++){
        if (s[i] == 'A') cnta++;
        if (s[i] == 'C') cnta = 0;
        if (s[i] == 'B' && (i + 1 >= n || s[i + 1] != 'C')) cnta = 0;
        if (i + 1 < n && s[i] == 'B' && s[i + 1] == 'C'){
            ans += cnta;
            i++;
        }
    }
    cout << ans;
}

int main()
{
    #ifdef HERE
        freopen("input.txt" , "r" , stdin);
    #else
        //freopen(".in" , "r" , stdin); freopen(".out" , "w" , stdout);
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #endif
    cout.precision(20);

    int t = 1;
    while(t --> 0){
        solve();
    }


    #ifdef HERE
        cout << setprecision(3) << fixed << "\n\nRuntime: " << (long double)(clock()) / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}
/*

*/
