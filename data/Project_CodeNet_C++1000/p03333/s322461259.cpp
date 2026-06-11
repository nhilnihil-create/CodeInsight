#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    
    ll n;
    cin>>n;
    array<ll,2> l[n],r[n];
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        l[i] = {a,i};
        r[i] = {b,i};
    }
    sort(l,l+n,greater<array<ll,2>>());
    sort(r,r+n);
    bool used[n]={};
    ll nl=0,nr=0;
    ll ans = max(0LL,0LL - r[nr][0]);
    ll now = r[nr][0];
    used[r[nr][1]] =1;
    nr=1;
    if(now<0)for(ll i=1;i<n;i++){
        while(nr<n && used[r[nr][1]]) nr++;
        while(nl<n && used[l[nl][1]]) nl++;
        ll dl = l[nl][0] - now;
        ll dr = now - r[nr][0];
        if(dl<=0 && dr<=0) break;
        if(dr > dl){
            now = r[nr][0];
            used[r[nr][1]]=1;
            ans += dr;
        }
        else if(dr==dl){
            ans += dr;
            if(nr<nl){
                now = r[nr][0];
                used[r[nr][1]]=1;
            }
            else {
                now = l[nl][0];
                used[l[nl][1]]=1;
            }
        }
        else {
            now = l[nl][0];
            used[l[nl][1]]=1;
            ans += dl;
        }
    }
    ans += abs(now);
    cerr << ans << endl;
    for(ll i=0;i<n;i++) used[i] = 0;
    nr=0,nl=0,now=0;
    ll ret = l[0][0];

    now = l[0][0];
    nl = 1;
    used[l[0][1]]=1;
    if(ret>0)for(ll i=1;i<n;i++){
        while(nr<n && used[r[nr][1]]) nr++;
        while(nl<n && used[l[nl][1]]) nl++;
        ll dl = l[nl][0] - now;
        ll dr = now - r[nr][0];
        if(dl<=0 && dr<=0) break;
        if(dr > dl){
            now = r[nr][0];
            used[r[nr][1]]=1;
            ret += dr;
        }
        else if(dr==dl){
            ret += dr;
            if(nr<nl){
                now = r[nr][0];
                used[r[nr][1]]=1;
            }
            else {
                now = l[nl][0];
                used[l[nl][1]]=1;
            }
        }
        else {
            now = l[nl][0];
            used[l[nl][1]]=1;
            ret += dl;
        }
    }
    ret += abs(now);
    ans = max(ret,ans);

    cout << ans << endl;

}