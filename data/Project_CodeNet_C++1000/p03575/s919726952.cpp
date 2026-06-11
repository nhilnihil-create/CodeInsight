#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
constexpr int MOD=1000000007;
//constexpr int MOD=998244353;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=2e5+5;

bool reach[50];
vector<int> edge[50];

void dfs(int now){
    if(reach[now]) return;
    reach[now]=true;
    rep(i,edge[now].size()) dfs(edge[now][i]);
}

int main(void){
    int N,M;
    cin >> N >> M;
    int A[M],B[M];
    rep(i,M) cin >> A[i] >> B[i];
    rep(i,M) A[i]--,B[i]--;
    int ans=0;
    rep(i,M){
        rep(j,N) edge[j].clear();
        rep(j,N) reach[j]=false;
        rep(j,M) if(i!=j) edge[A[j]].push_back(B[j]),edge[B[j]].push_back(A[j]);
        dfs(0);
        bool check=false;
        rep(j,N) if(!reach[j]) check=true;
        if(check) ans++;
    }
    cout << ans << endl;
}