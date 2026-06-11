#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()
#define pb push_back
template<class T>void chmax(T &a,T b){if(a<b)a=b;}
template<class T>void chmin(T &a,T b){if(a>b)a=b;}
constexpr int INF=1000000000000000000;
constexpr int mod=1000000007;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[2000010];
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
void init_fact(){
    kaijo[0]=1;
    for(int i=1;i<=2000001;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=mod;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%mod;
    int memo=modpow(a,b/2);
    return memo*memo%mod;
}
int comb(int a,int b){
    if(!kaijo[0])init_fact();
    return kaijo[a]*modpow(kaijo[a-b],mod-2)%mod*modpow(kaijo[b],mod-2)%mod;
}
int inv(int x){return modpow(x,mod-2);}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
int n,m;
string s;
vector<int>v[200010];
bool used[200010];
void dfs(int x){
    bool A=false,B=false;
    for(int i:v[x]){
        if(s[i]=='A'&&!used[i])A=true;
        if(s[i]=='B'&&!used[i])B=true;
    }
    if(A&&B)return;
    used[x]=true;
    for(int i:v[x]){
        if(!used[i])dfs(i);
    }
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    rep(i,n){
        if(!used[i])dfs(i);
    }
    bool ans=false;
    rep(i,n){
        if(!used[i])ans=true;
    }
    if(ans)puts("Yes");
    else puts("No");
    return 0;
}
