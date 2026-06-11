#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
// #define int long long
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


unordered_map<int,int>mm;
int temp=0;

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

    string a;
    cin>>a;
    int n=a.length();
    for(int i=0;i<n;i++)
    {
        temp^=(1<<(a[i]-'a'));  
        for(int j=0;j<26;j++)
        {
            int z=(temp^(1<<j));
            if(z==0)
                mm[temp]=1;
            else if(temp==0)
                mm[temp]=1;
            else if(mm[temp]!=0 && mm[z]!=0)
                mm[temp]=min(mm[temp],mm[z]+1);
            else if(mm[temp]==0&& mm[z]!=0)
                mm[temp]=mm[z]+1;
        }
        if(temp==0)
            mm[temp]=1;
    }
    if(temp==0)
        cout<<1;
    else
        cout<<mm[temp];
    
} 
    
