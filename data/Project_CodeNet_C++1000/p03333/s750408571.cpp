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
    pair<int,int>p[n+1];
    set<pair<int,int> >s1;
    set<pair<int,int>,greater<pair<int,int> > >s2;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
        s2.insert({p[i].first,i});
        s1.insert({p[i].second,i});
    }
    int tot=0;
    int x=0;
    int mx=0;
    while (!s1.empty())
    {
        auto j=s1.begin();
        int ind=j->second;
        if(!(p[ind].first<=x && p[ind].second>=x))
        {
            tot+=abs(j->first-x);
            x=j->first;
        }
        s2.erase({p[j->second].first,j->second});
        s1.erase(j);
        if(!s2.empty())
        {
            j=s2.begin();
            int ind=j->second;
            if(!(p[ind].first<=x && p[ind].second>=x))
            {
                tot+=abs(j->first-x);
                x=j->first;
            }
            s1.erase({p[j->second].second,j->second});
            s2.erase(j);
        }
    }

    tot+=abs(x);
    mx=max(mx,tot);
    tot=0;
    s1.clear();
    s2.clear();
    for(int i=1;i<=n;i++)
    {
        s2.insert({p[i].first,i});
        s1.insert({p[i].second,i});
    }
    x=0;
    while (!s2.empty())
    {
        auto j=s2.begin();
        int ind=j->second;
        if(!(p[ind].first<=x && p[ind].second>=x))
        {
            tot+=abs(j->first-x);
            x=j->first;
        }
        s1.erase({p[j->second].second,j->second});
        s2.erase(j);
        if(!s1.empty())
        {
            j=s1.begin();
            int ind=j->second;
            if(!(p[ind].first<=x && p[ind].second>=x))
            {
                tot+=abs(j->first-x);
                x=j->first;
            }
            s2.erase({p[j->second].first,j->second});
            s1.erase(j);
        }
    }
    tot+=abs(x);
    mx=max(mx,tot);
    cout<<mx;

} 
    
