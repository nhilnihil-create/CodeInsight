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
const int N=16;

//dp[mask] tells the maximum profit if the subsets of rabbits represented by mask
//are already grouped.

//profit[mask] tells the total profit we get if we put all the rabbits represented by
//mask in a single group

ll dp[1<<N],profit[1<<N];

void rec(int ind,vector<int> &not_taken,int mask,ll sum_till_now,int new_group)
{
    if(ind==(int)not_taken.size())
    {
        dp[mask]=max(dp[mask],sum_till_now+profit[new_group]);
        
        return;
    }
    
    //take the rabbit represented by ind in our new group
    rec(ind+1,not_taken,mask^(1<<not_taken[ind]),sum_till_now,
                                                  new_group^(1<<not_taken[ind]));
    
    //do not take this rabbit in the new group
    rec(ind+1,not_taken,mask,sum_till_now,new_group);
}

int main()                  
{
    int n;
    
    scn(n);
    
    int cost[n][n];
    
    rep(i,0,n)
    {
        rep(j,0,n)
        scn(cost[i][j]);
    }
    
    //I can keep all dp values initially 0 as we can get a profit of zero if we give
    //each rabbit a distinct group
    
    //preprocess the profit array
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        if(mask&(1<<i))
        {
            for(int j=i+1;j<n;j++)
            if(mask&(1<<j))
            profit[mask]+=1LL*cost[i][j];
        }
    }
    
    //iterate over already taken masks
    for(int mask=0;mask<(1<<n);mask++)
    {
        vector<int> not_taken;
        
        for(int i=0;i<n;i++)
        if(!(mask&(1<<i)))
        not_taken.pb(i);
        
        //recurse over forming a new group of some subset
        //from those who are not already taken
        
        rec(0,not_taken,mask,dp[mask],0);
    }
    
    //ans will be in all bits set mask as we have to give each rabbit exactly one group
    printf("%lld ",dp[(1<<n)-1]);
} 