#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// mt19937 gen_rand_int(chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 gen_rand_ll(chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int mm[1000005];
int pre[1000005];
int tot[1000005];
int sum[1000005];
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


    int n;
    cin>>n;
    string a;
    cin>>a;
    a="#"+a;
    int x=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='M')
            x++;
        else if(a[i]=='C')
        {
            mm[i]=x;        
            tot[i]++;
        }
        tot[i]+=tot[i-1];
        pre[i]=pre[i-1]+mm[i];
        sum[i]=x;
    }

    int q;
    cin>>q;
    while (q--)
    {
        int k;
        cin>>k;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='D')
            {
                ans+=pre[min(n,i+k-1)]-pre[i];            
                ans-=(tot[min(n,i+k-1)]-tot[i])*sum[i];
            }
        }
        cout<<ans<<'\n';
    }
    
} 
    
