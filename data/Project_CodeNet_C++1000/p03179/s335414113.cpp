//Author:- S_Aditya

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define ll long long 
#define scn(n) scanf("%d",&n)
#define lscn(n) scanf("%lld",&n)
#define lpri(n) printf("%lld",n)
#define pri(n) printf("%d",n)
#define pln() printf("\n")
#define priln(n) printf("%d\n",n)
#define lpriln(n) printf("%lld\n",n)
#define rep(i,init,n) for(int i=init;i<n;i++)
#define pb push_back     
#define mp make_pair
#define F first
#define S second
#define gcd __gcd
#define inf INT_MAX
#define ninf INT_MIN
const ll mod=1e9+7;         
const int N=3e3+4;

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

//dp[i][j] tells the no. of permutations of numbers from [1 to i] considering the 
//comparision string for the first i numbers with the ith letter of all these 
//permutations being j.

int dp[N][N];

int main()                  
{
    int n;
    
    scn(n);
    
    string comp;
    
    cin>>comp;
    
    dp[1][1]=1; //one way to fill a single length permutation and last digit should be 1

    for(int len=2;len<=n;len++)
    {
        //compute prefix sums of the dp states of len-1
        for(int i=1;i<=len-1;i++)
        add_self(dp[len-1][i],dp[len-1][i-1]);
        
        for(int last_digit=1;last_digit<=len;last_digit++)
        {
            int l,r;
            
            if(comp[len-2]=='<')
            l=1,r=last_digit-1;
            else
            l=last_digit,r=len-1;
            
            add_self(dp[len][last_digit],dp[len-1][r]);
            
            sub_self(dp[len][last_digit],dp[len-1][l-1]);
        }
    }
    
    int ans=0;
    
    for(int last_digit=1;last_digit<=n;last_digit++)
    add_self(ans,dp[n][last_digit]);
    
    printf("%d ",ans);
} 