#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

long long power(long long a, long long b,long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a %m;
        a = a * a %m;
        b >>= 1;
    }
    return res;
}


vector<int>bit[30][2];
int pp[35];
int mm[35];


signed main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    pp[0]=1;
    for(int i=1;i<=30;i++)
        pp[i]=pp[i-1]*2;
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<30;j++)
        {
            int x=(b[i]&(pp[j]-1));
            if(pp[j]&b[i])
                bit[j][1].push_back(x);
            else
                bit[j][0].push_back(x);
        }
    }    
    for(int i=0;i<30;i++)
    {
        sort(bit[i][0].begin(),bit[i][0].end());
        sort(bit[i][1].begin(),bit[i][1].end());        
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<30;j++)
        {
            int loda=(a[i]&(pp[j]-1));
            if(a[i]&pp[j])
            {
                int sz=bit[j][1].size();
                int l=0,r=sz-1;
                int mn=sz;
                int bc=pp[j];
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(bit[j][1][mid]+loda>=bc)
                    {
                        r=mid-1;
                        mn=min(mn,mid);
                    }
                    else
                    {
                        l=mid+1;
                    }                    
                }
                mm[j]+=sz-mn;
                l=0;
                sz=bit[j][0].size();
                r=sz-1;
                int mx=-1;
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(bit[j][0][mid]+loda>=bc)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        mx=max(mx,mid);
                        l=mid+1;
                    }                    
                }
                mm[j]+=mx+1;
            }
            else
            {
                int sz=bit[j][0].size();
                int l=0,r=sz-1;
                int mn=sz;
                int bc=pp[j];
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(bit[j][0][mid]+loda>=bc)
                    {
                        r=mid-1;
                        mn=min(mn,mid);
                    }
                    else
                    {
                        l=mid+1;
                    }                    
                }
                mm[j]+=sz-mn;
                l=0;
                sz=bit[j][1].size();
                r=sz-1;
                int mx=-1;
                while (l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(bit[j][1][mid]+loda>=bc)
                    {
                        r=mid-1;
                    }
                    else
                    {
                        mx=max(mx,mid);
                        l=mid+1;
                    }                    
                }
                mm[j]+=mx+1;
            }
        }
    }
    int res=0;
    for(int i=0;i<30;i++)
    {
        res+=(mm[i]%2)*pp[i];
    }
    cout<<res;

}       
