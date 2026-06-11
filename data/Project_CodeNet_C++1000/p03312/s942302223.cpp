#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl

ll n,cnt,ans,a[ohara],b,c,d,e,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

bool ok(ll ret,ll ce){
    ll le,ri;
    le=a[ret-1];
    ri=a[ce-1]-a[ret-1];
    if(ri>=le)return true;
    else return false;
}

void solve1(ll ce){
    ll le=1,ri=ce-1,mid;
    while(ri-le>1){
        mid=(le+ri)/2;
        if(ok(mid,ce)){
            le=mid;
        }
        else{
            ri=mid;
        }
    }
    tmp=LINF;
    rrep(i,max(1LL,le),min(ce,ri+1)){
        if(tmp>=abs(a[i-1]-(a[ce-1]-a[i-1]))){
            tmp=abs(a[i-1]-(a[ce-1]-a[i-1]));
            b=a[i-1];
            c=a[ce-1]-a[i-1];
        }
    }
    return;
}

bool ok1(ll ret,ll ce){
    ll le,ri;
    le=a[ret-1]-a[ce-1];
    ri=a[n-1]-a[ret-1];
    if(ri>=le)return true;
    else return false;
}

void solve2(ll ce){
    ll le=ce+1,ri=n-1,mid;
    while(ri-le>1){
        mid=(le+ri)/2;
        if(ok1(mid,ce)){
            le=mid;
        }
        else{
            ri=mid;
        }
    }
    tmp=LINF;
    rrep(i,max(ce+1,le),min(n,ri+1)){
        if(tmp>=abs((a[i-1]-a[ce-1])-(a[n-1]-a[i-1]))){
            tmp=abs((a[i-1]-a[ce-1])-(a[n-1]-a[i-1]));
            d=a[i-1]-a[ce-1];
            e=a[n-1]-a[i-1];
        }
    }
    return;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)cin>>a[i];
    rrep(i,1,n)a[i]+=a[i-1];
    ans=LINF;
    rrep(ce,2,n-1){
        b=0;c=LINF;d=0;e=LINF;
        solve1(ce);
        solve2(ce);
        ans=min(ans,max({b,c,d,e})-min({b,c,d,e}));
    }
    Cout(ans);
    return 0;
}
