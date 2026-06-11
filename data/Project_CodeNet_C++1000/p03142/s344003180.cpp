#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
const int INF=1e9,MOD=1e9+7,ohara=1e6+10;
const ll LINF=1e18;
using namespace std;
    
#define rep(i,n) for(ll (i)=0;(i)<(int)(n);(i)++)
#define rrep(i,a,b) for(ll i=(a);i<(b);i++)
#define rrrep(i,a,b) for(ll i=(a);i>=(b);i--)
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
#define p_b push_back
    
ll n,cnt,ans,a[ohara],b[ohara],c,d,tmp,tmpp,m,h,w,x,y,sum,pos,k,q;
ld doua;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
//int dy[]={-1,0,1,-1,1,-1,0,1};
//int dx[]={-1,-1,-1,0,0,1,1,1};
string alph("abcdefghijklmnopqrstuvwxyz"),s;
bool fl;
struct edge{int to,cost;};
V g[ohara];
ll nene[ohara],ne,out[ohara];
ll dp[ohara];
V kae[ohara];
    
//------ Believe yourself as a genius!!!!!! ------
    
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>n>>m;
    rep(i,n+m-1){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
        g[a[i]].p_b(b[i]);
        nene[b[i]]++;
    }
    rep(i,n){
        if(nene[i]==0){
            ne=i;
            break;
        }
    }
    queue<ll> que;
    que.push(ne);
    while(1){
        if(que.empty())break;
        ll moto=que.front();
        que.pop();
        rep(i,Size(g[moto])){
            ll to=g[moto][i];
            nene[to]--;
            if(nene[to]==0)que.push(to);
            dp[to]=max(dp[to],dp[moto]+1);
        }
    }
    rep(i,n+m-1){
        if(dp[a[i]]+1==dp[b[i]])continue;
        out[i]=1;
    }
    rep(i,n+m-1){
        if(out[i])continue;
        kae[b[i]].p_b(a[i]);
    }
    rep(i,n){
        if(i==ne)Cout(0);
        else Cout(kae[i][0]+1);
    }
    return 0;
}