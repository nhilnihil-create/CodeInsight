#include <iostream>
#include <bits/stdc++.h>
using namespace std;



double dp[301][301][301];

double compute(int one, int two, int three,int n )
{
    if(one<0 || two<0 || three<0)
        return 0;
    if((one==0) && (two==0) && (three==0))
        return 0;
    if(dp[one][two][three]>0)
        return dp[one][two][three];

    int re=one+two+three;
    double ans= (n+one*compute(one-1,two,three,n)+two*compute(one+1,two-1,three,n)+three*compute(one,two+1,three-1,n))/re;
    dp[one][two][three]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int one=0;
    int two=0;
    int three=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
            one++;
        else if(arr[i]==2)
            two++;
        else if(arr[i]==3)
            three++;
    }
    memset(dp,-1, sizeof dp);
    cout<<fixed<<setprecision(9)<<compute(one,two,three,n)<<endl;
    return 0;
}
