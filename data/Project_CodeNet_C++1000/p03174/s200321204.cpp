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

const int N=1<<21;
ll dp[22][N],n;
vector<vector<int>> a(22,vector<int>(22));

ll go(int pos, int mask){
    if(pos==n) return 1;
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[pos][i] && (mask&(1<<i))==0)
            ans=(ans+go(pos+1,mask|(1<<i)))%mod;
    }
    return dp[pos][mask]=ans;
}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=clock();
    
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(ll i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    cout<<go(0,0);

    

    cerr<<"\n\nTIME: "<<(double)(clock()-T)/CLOCKS_PER_SEC<<" sec\n";
    T = clock();
    return 0;
}