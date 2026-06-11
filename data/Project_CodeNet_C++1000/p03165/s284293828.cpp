#include <bits/stdc++.h>
using namespace std;

#define     FasterIO        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define     bug(a,b)        cout<<a<<"\t"<<b<<"\n";
#define     Case(a,b)       cout<<"Case "<<a<<": "<<b<<"\n";
#define     precision(a,b)  fixed<<setprecision(a)<<b
#define     lp(i,a,b)       for(int i=a;i<b;i++)
#define     Endl            "\n"
#define     tab             "\t"
#define     reset(a,b)      memset(a,b,sizeof(a));
#define     sf(a)           scanf(" %d", &a);
#define     sfl(a)          scanf(" %lld", &a);
#define     srt(a)          sort(a.begin(),a.end());
#define     ALL(a)          a.begin(),a.end()
#define     pb(a)           push_back(a)
#define     pi              2*acos(0.0)

typedef long long int ll;
typedef unsigned long long int ull;

const int sz=1e5+9 , infP=INT_MAX , infN=INT_MIN ,mod=1e9+7, eps=1e-9;


void ini(){

    return;
}

int dp[3005][3005];

void solve(){
    ll n , m, k, l, r;
    string s,t,ans="";
    cin>>s>>t;
    n=s.size(),m=t.size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(s[i-1]==t[j-1])dp[i][j]=dp[i-1][j-1]+1;
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }

/*
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<"  "; 
                 cout<<Endl;
    }*/

    int curI=n,curJ=m;
    while(curI>0 && curJ>0){
        if(dp[curI][curJ]==dp[curI-1][curJ]){
            curI--;
            continue;
        }
        if(dp[curI][curJ]==dp[curI][curJ-1]){
            curJ--;
            continue;
        }
        curI--,curJ--;
        ans+=s[curI];

    }

    reverse(ALL(ans));
    cout<<ans<<Endl;
}

int main(){
    FasterIO;
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.in","w",stdout);
    #endif
    // ini();
    int t=1;
    // cin>>t;
    while(t--)
        solve();
}
