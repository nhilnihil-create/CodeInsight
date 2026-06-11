#include<bits/stdc++.h>
using namespace std;
#define int long long int
//var=var%(1000000007);
#define mod 1000000007

int dp[21][1<<21];
int solve(int arr[][21],int &n,int visit,int ind)
{  if(ind==n)
    {
        return 1;
    }
    if(dp[ind][visit]!=-1)
      return dp[ind][visit];

    int var=0;
    for(int i=0;i<n;i++)
    { if(arr[ind][i]==1 && (((visit&(1<<(i)))==0)))
        { int num=visit|(1<<i);
                //cout<<ind+1<<" "<<i+1<<endl;
            var=( (var%mod)+(solve(arr,n,num,ind+1)%mod) )%mod;


        }
    }

     dp[ind][visit]=var;
     return var;
}
signed main()
{ int n;
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>n;

int arr[21][21]={0};
memset(arr,0,sizeof(arr));
memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];


    int ans=0,z=0;

    ans=solve(arr,n,z,0);

    cout<<ans<<endl;
}
