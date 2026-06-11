#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e5+5;
 
ll n;
ll pre[maxn];
ll c[maxn<<1], s[maxn];
 
ll lowbit(ll x) {return x&(-x);}
 
ll query(ll x){
    ll res = 0;
    for(ll i = x; i ; i -= lowbit(i)){
        res += c[i];
    }
    return res;
}
 
void add(ll x){
    for(ll i = x; i <= 2*n; i += lowbit(i)){
        c[i] += 1;
    }
}
 
bool check(ll x){
    memset(c, 0, sizeof(c));
    s[0] = 0;
    for(ll i = 1; i <= n; i++) {
        s[i] = pre[i]>=x?1:-1;
        s[i] += s[i-1];
    }  
    ll sum = 0;
    for(ll i = 0; i <= n; i++){
        sum += query(s[i]+n);
        add(s[i]+n);
    }
    ll num = n*(n+1)/2, ss;
    if (num%2) ss = (num+1)/2;
    else ss = num/2;
    if (sum >= ss) return true;
    return false;
}
 
int main () {
    cin >> n;
     
    ll l = 1, r = 1;
    for(ll i = 1; i <= n; i++) {
        scanf("%lld", &pre[i]);
        if (pre[i] > r) r = pre[i]; 
    }
     
     
    ll ans;
    while(l <= r){
        ll mid = (l+r)>>1;
        if (check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }
     
    printf("%lld\n", ans); 
     
    return 0;
}