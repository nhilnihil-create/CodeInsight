/*
https://t.me/unstoppabIesoIvemachinechannel
*/
#pragma ARCENIY_KIRILLOV_POVELITEL_KROKODILOV
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







ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd (b, a % b);
}



signed main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll g = gcd(b, d);
        if (b > a || b > d){
            cout << "No" << '\n';
            continue;
        }
        if (c >= b){
            cout << "Yes" << '\n';
            continue;
        }
        ll ost = a%g;
        if (b/g > c/g + 1){
            cout << "No" << '\n';
            continue;
        }
        ll osta = c%g;
        if ( (osta < ost) ){
            cout << "No" << '\n';
        }else cout << "Yes" << '\n';
    }




}
