#include <bits/stdc++.h>
#define int long long int
#define pb push_back

#define mod 1000000007
#define sp fixed<<setprecision(12)
using namespace std;
/*
const int MAX=10000005;
//vector<int> primes;
bitset<MAX> is_prime;
void sieve(){
    is_prime.set();
    is_prime[0]=is_prime[1]=0;
    for(int i=4;i<MAX;i+=2){
        is_prime[i]=0;
    }
    for(int i=3;i*i<MAX;i+=2){
        if(is_prime[i]){
            //primes.pb(i);
            for(int j=i*i;j<MAX;j+=i){
                is_prime[j]=0;
            }
        }
    }
}
*/
/*
void lcs(char s1[],char s2[]){
    int n=strlen(s1);
    int m=strlen(s2);
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int sum=0;
            if(s1[i-1]==s2[j-1]){
                sum=1+dp[i-1][j-1];
            }
            else{
                sum=max(dp[i-1][j],dp[i][j-1]);
            }
            dp[i][j]=sum;
        }
    }
    
    int index=dp[n][m];
    //cout<<index<<endl;
    char ans[index+1];
    ans[index]='\0';
    index--;
    int x=n;
    int y=m;
    while(x>0 and y>0){
        if(dp[x-1][y]==dp[x][y-1] and dp[x-1][y]!=dp[x][y]){
            ans[index]=s1[x-1];
            index--;
            x--;
            y--;
        }else if(dp[x-1][y]>dp[x][y-1]){
            x--;
        }else{
            y--;
        }

    }
    //reverse(ans.begin(),ans.end());

    cout<<ans;
    return;
}
*/
int dp[101][100005];
int a[101];

void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=a[0];i++){
        dp[0][i]=1;
    }
    for(int i=1;i<n;i++){
        vector<int> pref(k+1);
        pref[0]=dp[i-1][0];
        for(int j=1;j<k+1;j++){
            pref[j]=(pref[j-1]+dp[i-1][j])%mod;
        }
        for(int j=0;j<k+1;j++){
            if(j>a[i]){
                dp[i][j]=(pref[j]-pref[j-a[i]-1]+mod)%mod;
            }else{
                dp[i][j]=pref[j];
            }
        }
    }
    cout<<dp[n-1][k]<<'\n';

}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    //double    pi=3.14159265358979323846;
    //sieve();
    int t=1;
    
    //cin>>t;

    for(int tc=1;tc<=t;tc++){
       solve();

    }
    
    return 0;
    
}