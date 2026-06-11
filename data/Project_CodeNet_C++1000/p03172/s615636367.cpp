#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "  = " << x << endl
typedef long long int ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

#define dbg2(x, y)                                                       \
    {                                                                    \
        cout << #x << ": " << (x) << " , " << #y << ": " << (y) << endl; \
    }
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i < n; i++)
#define foA(i, A) for (auto i : A)
const int mxN=101;
const int modd=1e9+7;
int a[mxN];
int suf[mxN];
int dp[mxN][100003];

int ans=0, n;
int rfun(int ind, int k){
    //dbg2(ind, k);deb(ans);
    if(ind==n){
        // ans++;if(ans>=modd){ans-=modd;}
        return 1;
    }
    if(k<0)return 0;
    if(dp[ind][k]!=-1)return dp[ind][k];
    int an=0;
    for(int i=max(0, (k-suf[ind+1]));i<=min(k, a[ind]);i++){
        //dbg2(i, ind);
        an+= rfun(ind+1, k-i);
        an%=modd;
    }
    return dp[ind][k]=an;
}

int main(){
    int k;cin>>n>>k;
    fo(i, n)cin>>a[i];
    sort(a, a+n);
    memset(dp, -1,sizeof dp);
    suf[n-1]=a[n-1];
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+a[i];
    }
    for(int j=0;j<=k;j++){
        if(j<=a[0])dp[0][j]=1;
        else dp[0][j]=0;
    }
    for(int i=1;i<n;i++){
        vector<int>v(k+1, 0);
        v[0]=dp[i-1][0];
        for(int j=1;j<=k;j++)v[j]=(dp[i-1][j]+v[j-1])%modd;
        for(int j=0;j<=k;j++){
            if(j>a[i]){
                dp[i][j]=(v[j]-v[j-a[i]-1]+modd)%modd;;
            }
            else dp[i][j]=v[j];
        }
    }
    ans=dp[n-1][k];
    //ans= rfun(0, k);
    cout<<ans;
}