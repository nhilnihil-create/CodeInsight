#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(int i=(a);i<(b);i++)
#define rrrep(i,a,b) for(int i=(a);i>=(b);i--)
#define all(v) (v).begin(), (v).end()
#define Size(n) (n).size()
#define Cout(x) cout<<(x)<<endl
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair

ll n,cnt,ans,a[ohara],b,c,d,tmp,tmpp,m,h,w,x,y,sum[ohara],pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

ll modinv(ll aa,ll mm){
    ll bb=mm,uu=1,vv=0;
    while(bb){
        ll tt=aa/bb;
        aa-=tt*bb;swap(aa,bb);
        uu-=tt*vv;swap(uu,vv);
    }
    uu%=mm;
    if(uu<0)uu+=mm;
    return uu;
}

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n;
    rep(i,n)cin>>a[i];
    rep(i,n)(sum[i+1]=modinv(i+1,MOD))%=MOD;
    rrep(i,1,n)(sum[i+1]+=sum[i])%=MOD;
    /// 1/1 1/2 1/3 1/4.....の累積和を逆元を用いてやってる
    rep(i,n){
        (ans+=(a[i]*(sum[i+1]+sum[n-i]-1))%MOD)%=MOD;
    }
    rrep(i,2,n+1)(ans*=i)%=MOD;
    Cout(ans);
    return 0;
}
