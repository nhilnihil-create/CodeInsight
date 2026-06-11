#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll mxn= 5e4+5;
// check for forloop
// intialize variable
// overflow
// go for easy solution
#define mod 1000000007
ll INF = 1000000000000000005LL;
//#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    rishabh();
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    int dp[n+1]={};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(i-a>=0)
        dp[i]+=dp[i-a];
    }
    for(int i=1;i<=n;i++){
        if(i-b>=0)
        dp[i]+=dp[i-b];
    }
    for(int i=1;i<=n;i++){
        if(i-c>=0){
            dp[i]+=dp[i-c];
        }
    }
    cout<<dp[n];
}