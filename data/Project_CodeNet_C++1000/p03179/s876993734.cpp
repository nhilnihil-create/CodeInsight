#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define mp make_pair
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=1e9+7;
const int N=3e3+5;
int dp[N][N],n;
int pre[N][N];
string s;

int Calc(int x,int l,int r);
int find(int x,int y);
int find2(int x,int y);

int32_t main(){
    IOS;
    cin>>n;
    cin>>s;
    memset(dp,-1,sizeof(dp));
    memset(pre,-1,sizeof(dp));
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans+find(n,i))%M;
    }
    cout<<ans<<endl;
}

int Calc(int x,int l,int r){
    return((find2(x,r)-find2(x,l-1)+M)%M);
}

int find(int x,int y){
    if(y<1||y>x) return(0);
    if(dp[x][y]!=-1) return(dp[x][y]);
    if(x==1) return(dp[x][y]=1);
    int res=0;
    char c=s[x-2];
    if(c=='<'){
        res=(res+Calc(x-1,(int)1,y-1))%M;
    }
    else{
        res=(res+Calc(x-1,y,x-1))%M;
    }
    return(dp[x][y]=res);
}

int find2(int x,int y){
    if(y==0){return(0);}
    if(pre[x][y]!=-1){return(pre[x][y]);}
    return(pre[x][y]=(find(x,y)+find2(x,y-1))%M);
}
