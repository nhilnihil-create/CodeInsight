#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int,int> PII;
typedef pair <ll, ll> PLL;
typedef pair <int,string> PIS;
typedef vector <int> vec;
typedef priority_queue<int> PQ;
#define endl '\n'
#define pi 3.141592653589793
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define fori(z,n)  for(int i=z;i<n;i++)
#define fork(z,n)  for(int k=z;k<n;k++)
#define forii(z,n) for(int i=z;i<=n;i++)
#define forkk(z,n) for(int k=z;k<=n;k++)
int maxElement(int arr[],int n)
{
    int maxi=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>maxi)
            maxi=arr[i];
    }
    return maxi;
}
int minElement(int arr[],int n)
{
    int mini=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<mini)
            mini=arr[i];
    }
    return mini;
}
string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    int last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}
const int MAX = 200005;
ll tree[MAX*4];
void updateQuery(int v, int tl, int tr, int index, ll value)
{
    if(tl==tr)
        tree[v] = value;
    else
    {
        int mid = tl + (tr-tl)/2;
        if(index<=mid)
            updateQuery(v*2+1,tl,mid,index,value);
        else
            updateQuery(v*2+2,mid+1,tr,index,value);
        tree[v] = max(tree[v*2+2],tree[v*2+1]);
    }
}
ll checkQuery(int v, int tl, int tr, int l, int r)
{
    if(l<=tl && r>=tr)
        return tree[v];
    if(l>tr || r<tl)
        return 0;
    int mid = tl + (tr-tl)/2;
    ll b1 = checkQuery(v*2+1,tl,mid,l,r);
    ll b2 = checkQuery(v*2+2,mid+1,tr,l,r);
    return max(b1,b2);
}
int main() 
{ 
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(tree,0,sizeof(tree));
    int n;cin>>n;
    int h[n],b[n];
    int maxi=INT_MIN;
    fori(0,n)
    {
        cin>>h[i];
        maxi = max(maxi,h[i]);
    }
    fori(0,n) cin>>b[i];
    ll dp[n];
    dp[0]=b[0];
    ll ans=dp[0];
    updateQuery(0,0,maxi,h[0],b[0]);
    fori(1,n)
    {
        ll c1 = checkQuery(0,0,maxi,0,h[i]-1);
        dp[i] = (ll)b[i] + c1;
        updateQuery(0,0,maxi,h[i],dp[i]);
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;
    cerr<<"Time elapsed"<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
    return 0;
}
