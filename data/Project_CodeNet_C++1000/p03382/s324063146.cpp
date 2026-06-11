#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define endl endl;cf
#define be begin()
#define sz size()
#define en end()
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=1;i<=b;++i)
#define forr(i,a,b) for(ll i=0;i<b;++i)
#define rngx mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define cf cout.flush()
int main()
{
    ios;
    ll n;
    cin >> n ;
    vl  v;
    forn(i , 1 , n)
    {
        ll x;
        cin >> x;
        v.pb(x);
    }
    sort(all(v));
    ll N = v[n-1];
    if(N%2 == 1)
    {
        ll f1 = N/2 ;
        ll f2 = f1+1;
        ll ans1 = 3e18 , ans2 = 3e18;
        ll r1 = -1 ,r2 = -1;
        ll from = -1;
        for(ll i = 0 ; i< n ; ++i){
            if(v[i] > f1) {
                from = i;
                break;
            }
            else {
                ll diff = f1 - v[i];
                if(diff < ans1){
                    ans1 = diff ;
                    r1 = v[i];
                }
            }
        }
        r2= v[from];
        ll diff1 = f1 - r1;
        ll diff2 = r2 - f2;
        if(diff1 < diff2){
            cout << N << " " << r1 <<endl;
        }
        else cout << N << " " << r2 << endl;
        return 0;
    }
    else if(N%2 == 0)
    {
        ll f = N/2;
        ll ans1 = 3e18;
        ll r1 = -1;
        for(ll i = 0 ; i <n-1 ; ++i){
            ll diff = abs(v[i] - f);
            if(diff < ans1){
                ans1 = diff ;
                r1 = v[i];
            }
        }
        cout << N << " " << r1 <<endl;
        return 0 ;
    }
}

