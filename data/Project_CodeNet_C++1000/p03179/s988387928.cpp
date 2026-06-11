#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define MAX 9223372036854775807
#define MIN -9223372036854775807
#define PI 3.141592653589
#define setbits(n) __builtin_popcountll(n)
const ll mod=1e9+7;

const int N=3e3+1;
ll dp[N][N],n,pref[N];
string s;

ll go(ll pos, ll last){
    if(pos==n-1) return 1;
    if(dp[pos][last]!=-1)
        return dp[pos][last];
    ll ans=0;
    if(s[pos]=='<'){
        for(int i=last+1;i<=pos+2;i++)
            ans=(ans+go(pos+1,i))%mod;
    }
    else{
        for(int i=1;i<=last;i++)
            ans=(ans+go(pos+1,i))%mod;
    }
    return dp[pos][last]=ans;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    cin>>s;
    //memset(dp,-1,sizeof(dp));
    //cout<<go(0,1);
    dp[1][1]=1;
    for(ll i=2;i<=n;i++){
        pref[0]=0;
        for(int j=1;j<=i-1;j++)
            pref[j]=(pref[j-1]+dp[i-1][j])%mod;
        for(ll j=1;j<=i;j++){
            int l,r;
            if(s[i-2]=='<')
                dp[i][j]+=(pref[j-1]-pref[0]+mod)%mod;
            else
                dp[i][j]+=(pref[i-1]-pref[j-1]+mod)%mod;
            dp[i][j]%=mod;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
        ans=(ans+dp[n][i])%mod;
    cout<<ans;

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}