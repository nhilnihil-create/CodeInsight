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
#define doublecout(a) cout<<fixed<<setprecision(15)<<a<<endl;
#define Cerr(x) cerr<<(x)<<endl
#define fi first
#define se second
#define P pair<ll,ll> 
#define m_p make_pair
#define V vector<ll> 
#define U_MAP unordered_map<ll,ll>
#define pq priority_queue<ll>
#define rpq priority_queue<ll,vector<ll>,greater<ll>>
    
ll n,cnt,ans,d,tmp,tmpp,m,h,w,x,y,sum,pos,k;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),a,b,c;
bool fl;
struct edge{int to,cost;};
    
//-------------------------↓↓↓↓↓↓------------------------
    
//------ 自分を天才だと信じる ------
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>a>>b>>c;
    rep(i,n){
        char aa,bb,cc;
        aa=a[i];
        bb=b[i];
        cc=c[i];
        map<char,ll> mp;
        cnt=0;
        mp[aa]++;
        cnt=max(mp[aa],cnt);
        mp[bb]++;
        cnt=max(mp[bb],cnt);
        mp[cc]++;
        cnt=max(mp[cc],cnt);
        ans+=3-cnt;
    }
    Cout(ans);
    return 0;
}