#include<bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define pb push_back
using namespace std;
ll n,pown=1,t[7000005],a[200005],b[200005],l,r,ans;
void upd(ll x){
    if(!x)return;
    t[x] = t[2 * x] + t[2 * x + 1];
    upd(x / 2);
}
ll cnt(ll x,ll L,ll R){
    if(L > r || R < l)return 0LL;
    if(L >= l && R <= r)return t[x];
    ll k1 = cnt(2 * x,L,(L + R)/2);
    ll k2 = cnt(2 * x + 1,(L+R)/2+1,R);
    return k1+k2;
}
bool check(ll x){
    for(int i=1; i<=n; i++){
        if(b[i] <= x)a[i] = 1;
        else a[i] = 0;
    }
    for(int i=1; i<=3 * pown; i++){
        t[i] = 0;
    }
    ll rr = 0,raod = 0;
    t[pown + n + 1 - 1]++;
    upd((pown + n + 1 - 1) / 2);
    for(int i=1; i<=n; i++){
        if(a[i] == 1)rr++;
        else rr--;
        l = 1;
        r = rr + n;
    //    cout << l << " " << r << " <--count\n";
        raod += cnt(1 , 1 , pown);
    //    cout << (rr + n + 1) << "<-- add\n";
        t[pown + (rr + n + 1) - 1]++;
        upd((pown + (rr + n + 1) - 1) / 2);
    }
//    cout << x << " " << raod << endl;
    if(raod * 2 > n * (n + 1) / 2)return 1;
    return 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    while(pown <= 3 * n)
        pown *= 2;
    for(int i=1; i<=n; i++)cin >> b[i];
    
    ll l=1,r=1000000000,mid;
    while(r >= l){
        mid = (l + r) / 2;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << ans << endl;
    
    
    return 0;
}
