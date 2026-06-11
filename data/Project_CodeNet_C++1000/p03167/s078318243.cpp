#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
unordered_map<int,list<int> > um;
int mod=1000000007;
void solve()
{
    int r,c;
    cin>>r>>c;
    char a[r][c];
    for(int i=0; i<r; i++){
        cin>>a[i];
    }
    int dp[r][c];
    memset(dp,0,sizeof(dp));
    dp[r-1][c-1]=1;
    for(int i=r-1; i>=0; i--){
        for(int j=c-1; j>=0; j--){
            if(a[i][j]=='#'){
                continue;
            }
            if(i+1<r && a[i][j]!='#'){
                dp[i][j]+=dp[i+1][j];
                dp[i][j]=dp[i][j]%(mod);
            }
            if(j+1<c && a[i][j]!='#'){
                dp[i][j]+=dp[i][j+1];
                dp[i][j]=dp[i][j]%(mod);
            }
        }
    }
    cout<<dp[0][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
