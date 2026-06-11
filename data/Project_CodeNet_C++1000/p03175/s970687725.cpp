/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mod 1000000007
int dp[100001][2];


int  mulmod(int a, int b) 
{ 
    int res = 0; // Initialize result 
    a = a % mod; 
    while (b > 0) 
    { 
        // If b is odd, add 'a' to result 
        if (b % 2 == 1) 
            res = (res + a) % mod; 
  
        // Multiply 'a' with 2 
        a = (a * 2) % mod; 
  
        // Divide b by 2 
        b /= 2; 
    } 
  
    // Return result 
    return res % mod; 
} 

int ways(int i,int par,int constrain,vector<vector<int>> &tree)
{
    if(tree[i].size()==0)
    {
        // uska koi child nhi hai....
        // recursion krte last mei aa gaye hain....
        return constrain?1:2;
    }
    else
    {
        if(dp[i][constrain]!=-1)
           return dp[i][constrain];
        
        if(!constrain)
        {
            // it can be both black and white.....
            int option1=1;  // white paint kiya ith node pr...
            for(auto child:tree[i])
            {
                if(child!=par)
                   //option1=((option1%mod)*(ways(child,i,0,tree)%mod))%mod;
                   option1=mulmod(option1,ways(child,i,0,tree));
            }
            int option2=1; // black paint kr diya ith node pr...
            // ab child pr constrain hoga...
            for(auto child:tree[i])
            {
                if(child!=par)
                   //option2=((option2%mod)*(ways(child,i,1,tree)%mod))%mod;
                   option2=mulmod(option2,ways(child,i,1,tree));
            }
            return dp[i][constrain]=(option1%mod+option2%mod)%mod;
        }
        else
        {
            // ith node is under constrain it can be white only..
            // bcz parent is black.....
            int option1=1;
            for(auto child:tree[i])
            {
                if(child!=par)
                   //option1=((option1%mod)*(ways(child,i,0,tree)%mod))%mod;
                   option1=mulmod(option1,ways(child,i,0,tree));
            }
            return dp[i][constrain]=option1%mod;
        }
    }
}

int solve(int n,vector<vector<int>> &tree)
{
    memset(dp,-1,sizeof(dp));
    return ways(1,-1,0,tree);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].pb(b);
        tree[b].pb(a);
    }
    cout<<solve(n,tree);
    

    return 0;
}





