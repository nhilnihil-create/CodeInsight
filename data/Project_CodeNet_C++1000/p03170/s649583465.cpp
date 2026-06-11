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

string solve(vector<int> &v,int n,int k)
{
    // initailly pile mei k stone hai...
    // hum hr eik stage ko define karenge,....
    // agar hum kisi particualr stage se aisi stage pr ja sakte hain..jahan se stones ko remove krna possible 
    // nhi hai tu in that case vo eik winning position hai...
    bool dp[k+1];
    // dp[i] will define whether it is possible for taru to win the game or not...
    for(int i=0;i<=k;i++)
    {
        if(i<v[0])
           dp[i]=false;
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(i-v[j]>=0)
            {
            if(dp[i-v[j]]==false)
            {
                flag=1;
                break;
            }
            }
            else // elements given are in the sorted form....
            {
                break;
            }
        }
        if(flag)
        {
            // it is possible to reach a particular stage from where we cant remove a stone...
            // so this is a winning stage...
            dp[i]=true;
        }
        else
        {
            dp[i]=false;
        }
    }
    return dp[k]==true?"First":"Second";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<solve(v,n,k);
    return 0;
}





