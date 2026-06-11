#include <bits/stdc++.h>
using namespace std;
const int nax=1e5+5;
const int mod=1e9+7;
#define ll long long

void add_self(int &a,int b)
{
    a+=b;
    if(a>=mod)
    a-=mod;
}

void sub_self(int &a,int b)
{
    a-=b;
    if(a<0)
    a+=mod;
}


int main()
{
    int n,k;
    cin >> n >> k;
    
    vector<int> dp(k+1);
    
    dp[0]=1;
    
    for(int child=0;child<n;++child)
    {
        int a;
        cin >> a;
        vector<int> fake(k+1);
        for(int candies=k;candies>=0;--candies)
        {
            int tmp=dp[candies];
            int l=candies+1;
            int r = candies + min(a,k-candies);
            
            if(l<=r)
            add_self(fake[l],tmp);
            if(r+1<=k)
            sub_self(fake[r+1],tmp);
        }
    int pref_sum=0;
    for(int i=0;i<=k;++i)
    {
        add_self(pref_sum,fake[i]);
        add_self(dp[i],pref_sum);
    }
    }
    cout << dp[k] << endl;
    
    return 0;
} 