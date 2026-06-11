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

const int N=3001;
int dp[N][N];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    string s,t;
    cin>>s>>t;
    ll n=s.size(), m=t.size();
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i>0) dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(j>0) dp[i][j]=max(dp[i][j],dp[i][j-1]);
            if(i>0&&j>0&&s[i-1]==t[j-1])
                dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
        }
    }
    //cout<<dp[n][m];
    ll i=n,j=m;
    string ans;
    while(i>0&&j>0){
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--,j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}