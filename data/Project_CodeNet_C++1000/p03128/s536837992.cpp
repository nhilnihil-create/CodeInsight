#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
typedef long long ll;
using namespace std;
int main(void){
    int n,m;cin>>n>>m;
    vector<int> a(m);
    rep(i,m) cin>>a[i];
    sort(a.rbegin(),a.rend());
    int tr[10]={0,2,5,5,4,5,6,3,7,6};
    string dp[n+1003];//i本のマッチ棒を使ってできる最大の整数
    dp[0]="";
    rep(i,n){
        if(i!=0&&dp[i].size()==0) continue;
        rep(j,m){
            int x=a[j];//最上段に着ける整数候補
            string now=dp[i];
            string nw=((char)(x+'0'))+now;
            if(dp[i+tr[x]].size()==0)dp[i+tr[x]]=nw;
            //if(dp[i+tr[x]]=="71")cout<<nw<<" "<<i<<endl;
            if(dp[i+tr[x]].size()<nw.size())dp[i+tr[x]]=nw;
            if(dp[i+tr[x]][0]-'0'<nw[0]-'0')dp[i+tr[x]]=nw;
            //if(dp[i+tr[x]]=="71")cout<<nw<<endl;
        }
    }
    string res=dp[n];
    //reverse(res.begin(),res.end());
    //rep(i,n+1)cout<<dp[i]<<" "<<i<<endl;
    cout<<res<<endl;
}
