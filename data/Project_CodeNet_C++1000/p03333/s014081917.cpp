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

ll n,cnt,ans,a,b,c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k,l[ohara],r[ohara];
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

    cin>>n;
    rep(i,n)cin>>l[i]>>r[i];
    //0から0の範囲を初期と最後原点に戻る行為としてとらえる
    sort(l,l+n+1);
    reverse(l,l+n+1);
    sort(r,r+n+1);
    rep(i,n+1){
        ans+=max(l[i]-r[i],0LL)*2;
    }
    Cout(ans);
    return 0;
}
