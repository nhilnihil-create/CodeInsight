#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; const int inf = 0x3fffffff; const ll INF = 0x3fffffffffffffff;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//template end

void solve(){
    ll a,b; scanf("%lld%lld",&a,&b);
    if(a==b){
        printf("%lld\n",2*a-2); return;
    }
    ll n=a*b-1,lb=1,rb=inf*2;
    while(rb-lb>1){
        ll mid=(lb+rb)/2;
        ll sum=(mid+1)/2*(mid+1-(mid+1)/2);
        (sum>n?rb:lb)=mid;
    }
    printf("%lld\n",lb-1);
}

int main(){
    int q; scanf("%d",&q);
    rep(rot,0,q)solve();
    return 0;
}