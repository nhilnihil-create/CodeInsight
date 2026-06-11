//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
//#pragma GCC target("popcnt")
//#pragma GCC target("sse4")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(),a.end()
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i > -1; i--)
#define rer(i, x, n) for (int i = x; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;














const int lim = 4000006;
signed main(){
    int n;
    cin >> n;
    int a[n];
    int S = 0;
    for (int i = 0; i < n; i++){cin >> a[i]; S += a[i];}
    bitset<lim> b;
    b[0] = 1;
    for (int i = 0; i < n; i++)
        b |= b << a[i];
    for (int j = (S + 1)/ 2; ; j++){
        if (b[j]){cout << j; return 0;}
    }


}
