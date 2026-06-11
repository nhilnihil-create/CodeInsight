#include <iostream>
#include<bits/stdc++.h>
using namespace std;
double dp[301][301][301];

double ways(int x,int y,int z,int n)
{
    if(x<0 || y<0 || z<0)
    {
        return 0;
    }
    if(x==0 && y==0 && z==0)
    {
        return dp[x][y][z]=0;
    }
    else
    {
        if(dp[x][y][z]>-0.9)
        {
            return dp[x][y][z];
        }
        
        double temp;
        temp=( n+x*ways(x-1,y,z,n)+y*ways(x+1,y-1,z,n)+z*ways(x,y+1,z-1,n) );
        return dp[x][y][z]=(temp/(x+y+z));
        
    }
}


double solve(int x,int y,int z,int n)
{
    memset(dp,-1,sizeof(dp));
    return ways(x,y,z,n);
}

int main()
{
    int n;
    cin>>n;
    int one,two,three;
    one=two=three=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            one++;
        }
        else if(x==2)
        {
            two++;
        }
        else if(x==3)
        {
            three++;
        }
    }
    //cout<<solve(one,two,three,n);
    cout<<fixed<<setprecision(12)<<solve(one,two,three,n);
    return 0;
}