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

ll n,cnt,ans=-1,a,b,c,d,tmp,tmpp,m,h,w,x[ohara],y,sum[ohara],pos,X;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>X;
    rep(i,n)cin>>x[i],sum[i+1]=x[i];
    rrep(i,1,n+1)sum[i+1]+=sum[i];
    rrep(k,1,n+1){
        cnt=(sum[n]-sum[max(n-2*k,0LL)])*5;
        ll kakeru=7;
        int ok=0;
        rrrep(i,n-2*k,0){
            if(cnt>=9223372036854775000-(sum[i]-sum[max(i-k,0)])*kakeru){ok=1;break;}
            cnt+=(sum[i]-sum[max(i-k,0)])*kakeru;
            kakeru+=2;
            i-=k-1;
        }
        if(ok)continue;
        if(k*X>=9223372036854775000-cnt)continue;
        if(ans==-1)ans=cnt+k*X;
        else ans=min(ans,cnt+k*X);
    }
    Cout(ans+X*n);
    return 0;
}
