#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define ar array
#define db long double
#define pow pw
const db pi = 3.14159265358979323846;
int pw(int a,int b){
    int ans=1;
    while(b){
    if (b%2) ans*=a;
    a*=a;
    b/=2;
    }
    return(ans);
}
const int mxn=1e5+7;
int dp[mxn];
int a[mxn];
int n,k;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<=k;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i>=a[j]&&!dp[i-a[j]]) dp[i]=1;
        }
    }
    if (dp[k]) cout<<"First";
    else cout<<"Second";
    return 0;
}