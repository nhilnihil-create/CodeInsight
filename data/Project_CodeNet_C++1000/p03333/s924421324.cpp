#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MAX=300005;
const ll INF=0x3f3f3f3f;
const ll MOD=998244353;
ll n,chk[MAX],pt,ans,ans_t;
struct range{
    ll x,y,idx;
};
range seg1[MAX],seg2[MAX];
bool cmp1(const range &a,const range &b){return a.x>b.x;}
bool cmp2(const range &a,const range &b){return a.y<b.y;}
int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;i++) scanf("%lld%lld",&seg1[i].x,&seg1[i].y),seg1[i].idx=i,seg2[i]=seg1[i];
    sort(seg1,seg1+n,cmp1),sort(seg2,seg2+n,cmp2);
    pt=0,ans_t=0;
    for(ll i=0;i<n;i++){
        if(chk[seg1[i].idx]==0){
            ll t=max(min(pt,seg1[i].y),seg1[i].x);
            chk[seg1[i].idx]=1;
            ans_t+=abs(pt-t), pt=t;
        }
        if(chk[seg2[i].idx]==0){
            ll t=max(min(pt,seg2[i].y),seg2[i].x);
            chk[seg2[i].idx]=1;
            ans_t+=abs(pt-t), pt=t;
        }
    }
    ans_t+=abs(pt);
    ans=max(ans_t,ans);
    for(ll i=0;i<n;i++) chk[i]=0;
    pt=0,ans_t=0;
    for(ll i=0;i<n;i++){
        if(chk[seg2[i].idx]==0){
            ll t=max(min(pt,seg2[i].y),seg2[i].x);
            chk[seg2[i].idx]=1;
            ans_t+=abs(pt-t), pt=t;
        }
        if(chk[seg1[i].idx]==0){
            ll t=max(min(pt,seg1[i].y),seg1[i].x);
            chk[seg1[i].idx]=1;
            ans_t+=abs(pt-t), pt=t;
        }
    }
    ans_t+=abs(pt);
    ans=max(ans_t,ans);
    printf("%lld\n",ans);
}
