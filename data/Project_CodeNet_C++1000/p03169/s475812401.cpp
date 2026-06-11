#include<bits/stdc++.h>
using namespace std;
double  dp[310][310][310];
int n;
double f(int i,int j,int k)
    {if(i+j+k==0){return (double)0;}
    if(dp[i][j][k]>-0.2){return dp[i][j][k];}
    double sumi=0;
    if(i)
        {sumi=sumi+i*(1+f(i-1,j,k));
        }
    if(j)
        {sumi=sumi+j*(1+f(i+1,j-1,k));
        }
    if(k)
        {sumi=sumi+k*(1+f(i,j+1,k-1));
        }
    sumi+=n-i-j-k;
    sumi=(double)sumi/(double)(i+j+k);
    dp[i][j][k]=sumi;
    return sumi;
    }
int main()
    {ios::sync_with_stdio(0);
    cin.tie(0);
    int count1=0;
    int count2=0;
    int count3=0;
    cin>>n;
    int dummy;
    for(int i=0;i<n;i++){cin>>dummy;
    if(dummy==1){count1++;}
    if(dummy==2){count2++;}
    if(dummy==3){count3++;}
    }
    for(int i=0;i<310;i++)
        {for(int j=0;j<310;j++)
            {for(int k=0;k<310;k++)
            {dp[i][j][k]=-1;}
            }
        }
    cout<<setprecision(12)<<f(count1,count2,count3);
    }
