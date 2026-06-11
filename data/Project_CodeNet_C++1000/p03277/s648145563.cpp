#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
#define MAXN 100005
#define MAXA 1000000005
#define pb push_back
#define INF 999999999999999LL
using namespace std;
ll n,ar[MAXN],ar1[MAXN],art[MAXN],ans,bl,br,bm,ba,st[7*MAXN],l[7*MAXN],r[7*MAXN],stx,sta;
void buil(ll i){
    if (l[i]==r[i]) return;
 
    l[i*2]=l[i]; r[i*2]=l[i]+(r[i]-l[i])/2;
    l[i*2+1]=r[i*2]+1; r[i*2+1]=r[i];
 
    buil(i*2); buil(i*2+1);
}
void add(ll i){
    st[i]++;
 
    if (l[i]==r[i]) return;
 
    if (stx<=r[i*2]) add(i*2); else add(i*2+1);
}
void ret(ll i){
    if (stx<l[i]) return;
 
    if (r[i]<=stx) { sta+=st[i]; return; }
 
    ret(i*2); ret(i*2+1);
}
int main(){
    cin>>n;
    for (int i=1; i<=n; i++) scanf("%lld",&ar[i]);
 
    l[1]=-n-3; r[1]=n+3;
    buil(1);
 
    bl=1; br=MAXA;
    while(bl<=br){
        bm=(bl+br)/2;
        
        sta=stx=0; add(1);
 
        for (int i=1; i<=n; i++){
            if (ar[i]<bm) ar1[i]=-1;
            else ar1[i]=1;
 
            if (i) ar1[i]+=ar1[i-1];
 
            stx=ar1[i]; ret(1); add(1);
        }
 
        for (int i=0; i<7*MAXN; i++) st[i]=0;
        
        // cout<<bm<<" - "<<sta<<endl;
 
        if (2LL*sta>=n*(n+1LL)/2LL){
            ans=bm;
            bl=bm+1;
        }
        else br=bm-1;
    }
 
    cout<<ans<<endl;
}
/*
10
5 9 5 9 8 9 3 5 4 3
*/