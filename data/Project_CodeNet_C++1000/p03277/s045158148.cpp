#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define endl '\n'
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define kill(x) return cout<<x<<'\n', 0;
using namespace std;
const int N=2e5+100;
ll fen[2*N];
void add(ll idx,ll val){
    for (idx;idx<2*N;idx+= idx & (-idx)) fen[idx]+=val;
}
ll get(ll idx){
    ll s=0;
    for (;idx;idx-= idx & (-idx)) s+=fen[idx];
    return s;
}
ll a[N];
int32_t main(){
    sync;
    ll n;
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    ll l=0,r=1e9+100;
    while(r-l>1){
        memset(fen,0,sizeof fen);
        ll mid=(r+l)/2;
        ll lazy=0;
        ll s=0;
        for (int i=n;i;i--){
            ll t=0;
            if (a[i]>=mid) t=1;
            else t=-1;
            lazy+=t;
            t=t-lazy;
            add(t+N,1);
            ll z=get(2*N-1)-get(-lazy+N-1);
            s+=z;
        }
        if (s*2>=(n+1)*n/2) l=mid;
        else r=mid;

    }
    cout << l << endl;
}
