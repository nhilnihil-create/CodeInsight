#include<bits/stdc++.h>
using namespace std;
 
#define reset(X) memset(X, 0, sizeof(X))
//#define int long long
typedef long long ll;
#define pb push_back
#define se second
#define fi first
#define endl '\n'
#define all(X) X.begin(),X.end()
 
const int INF=2e18;
const int mod=1e9+7;
const int mod2=998244353;
 
 
 
#define readn(a) int a;cin>>a;
#define readv(a,n) vector<int> a(n);for(int i=0;i<n;i++)cin>>a[i];
#define reada(a,n,m) int a[n][m];for(int i=0;i<n;i++)for(int j=0;j<m;j++) cin>>a[i][j];
 
 
 
typedef vector<int> vi;
typedef pair<int, int> pii;
int pow(int a, int b, int mod)
{
    int prod=1;
    int mult=a;
    while(b!=0)
    {
        if(b%2)
        {
            prod*=mult;
            prod%=mod;
        }
        mult*=mult;
        mult%=mod;
        b/=2;
    }
    return prod;
}
int mod_inv(int q, int mod)
{
    return pow(q, mod-2, mod);
}


const int MAXN=2e3+10;
bitset<MAXN*MAXN> arr[2] ;
signed main()
{
 
  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    if (fopen("INPUT.txt", "r")) {
        freopen ("INPUT.txt" , "r" , stdin);
        freopen ("OUTPUT.txt" , "w" , stdout);
    }
    #endif
//---------------------------------------------------------------------------------------------------
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(all(a));
    arr[0].set(0);
    int prev=0, next=1;
    for(int i=1;i<=n;i++)
    {
        arr[next]=arr[prev]|(arr[prev]<<(a[i-1]));
        swap(prev, next);
    }
    int k=accumulate(all(a), (int)0);
    
    pair<int, int> best={INF, -1};
    for(int i=(k+1)/2;i<MAXN*MAXN;i++)
    {
        if(arr[prev][i]!=0)
        best=min(best, {i-k/2, i});
    }
    cout<<best.se<<endl;
}