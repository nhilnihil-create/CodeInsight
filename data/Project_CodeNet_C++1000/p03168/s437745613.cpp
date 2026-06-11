#include<iostream>
using namespace std;
#define ll long long 
#include<bits/stdc++.h>
#define mod 1000000007
//Recursive approach
/*
double mul = 0;
void coins_pr(double* a, int n, double sum,int i ,int c,int x)
{
    if(i>=n)
    return;

    for(int j=i;j<n;j++)
    {
        if(c<x)
        {

         double sum1 = (sum/a[j])*(1-a[j]);
         mul += sum1;
         coins_pr(a,n,sum1,j+1,c+1,x);
        }
        else
        break;
    }
    return;
}*/
//Dp approcah
int main()
{
 	int n;
     cin>>n;
     double a[n];
     double sum=1.0;
     for(int i=0;i<n;i++)
    {
    cin>>a[i];
    sum*=a[i];
    }
    /*int x = n%2==1?n/2:n/2-1;
    coins_pr(a,n, sum,0,0,x);
    mul += sum;
    cout<<mul<<endl;*/
    cout<<fixed;
    cout<<setprecision(10);
    double dp[n+1][n+1];
    dp[0][0] = 1.0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        dp[i][j] = 1.0;
    }
for(int i=1;i<=n;i++)
{
    for(int j=0;j<=i;j++)
    {
            if(j==0)
            {
                dp[i][j] = dp[i-1][j]*(1-a[i-1]);
            }
            else if(i==j)
            {
                dp[i][j] = dp[i-1][j-1]*a[i-1];
            }

            else
            {
                dp[i][j] = dp[i-1][j]*(1-a[i-1]) + dp[i-1][j-1]*a[i-1];
            }
    }
}
double mul = 0;
for(int i=n/2+1;i<=n;i++)
mul += dp[n][i];
cout<<mul<<endl;
}