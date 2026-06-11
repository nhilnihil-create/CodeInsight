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
int n;
int dp[100005][2];

bool rfun(int k, bool ch){
    if(k<a[0])return 0;
    if(dp[k][ch]!=-1)return dp[k][ch];
    for(int i=0;i<n;i++){
        if(k-a[i]<0)break;
        if(rfun(k-a[i], !ch)==0)return dp[k][ch]=1;
    }
    return dp[k][ch]=0;
}

int main(){
    int k;
    cin>>n>>k;
    fo(i, n)cin>>a[i];
    sort(a, a+n);
    memset(dp, -1, sizeof dp);
    if(rfun(k, 0))cout<<"First";
    else cout<<"Second";
}