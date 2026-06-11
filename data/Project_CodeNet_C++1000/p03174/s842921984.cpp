#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll dp[25][2100000];
bool mat[25][25];
unsigned long long int popcount(unsigned long long int n){
    if(n==0) return 0;
    return 1+popcount(n&(n-1));
}
void solve(){
	ll i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++) cin>>mat[i][j];
    }
    const ll MX = pow(2,n)-1;
    for(i=0;i<=MX;i++) dp[0][i]=0;
    dp[0][0]=1;
    for(i=1;i<=n;i++){
        //i is the man
        for(j=0;j<=MX;j++){
            //j is the mask
            dp[i][j]=0;
            ll ppc=popcount(j);
            if(ppc==i){//only if numbers of women left is equal to i(=no of men)
                for(k=0;k<n;k++){
                    //kth woman is to be matched
                    if( (j&(1<<k)) && mat[i][k]) //if kth women present in j && is kth women allowed by question
                        dp[i][j]+=dp[i-1][j-(1<<k)];
                    dp[i][j]%=MOD;
                }
            }
        }
    }
    cout<<dp[n][MX]<<endl;
}
int main(){
    solve();
	return 0;
}
