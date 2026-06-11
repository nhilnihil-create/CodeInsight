#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int ma=3005;
ll dp[ma][ma];
ll s[ma][ma];
const int MOD = (1e9 + 7);
int add(int a, int b)
{
    a+=b;
    while(a>=MOD) a-=MOD;
    return a;
}
int sum(int i, int l, int r)
{
    if(l>r) return 0;
    if(l==0) return s[i][r];
    else return add(s[i][r],MOD-s[i][l-1]);
}
void solve(){
    int n;
    string st;
    cin>>n>>st;
    dp[0][0]=1;
    s[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(st[i-1]=='<'){
                dp[i][j]=sum(i-1,0,j-1);
            }
            else{
                dp[i][j]=sum(i-1,j,i-1);
            }
        }
        for(int j=0;j<=i;j++){
            s[i][j]=dp[i][j];
                s[i][j]=add(s[i][j],s[i][j-1]);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) ans=add(ans,dp[n-1][i]);
    cout<<ans<<endl;

}
int main(){
    int t=1;

    while(t--)solve();

}
