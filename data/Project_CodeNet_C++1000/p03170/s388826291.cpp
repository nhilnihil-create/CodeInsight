/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
int dp[100007];
int main()
{
    int n,k,i,j;
    cin>>n>>k;
    int arr[n];
    for(i=0;i<n;i++){cin>>arr[i];}
    for(i=0;i<=k;i++){dp[i]=0;}
    for(i=arr[0];i<=k;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=arr[j]&&dp[i-arr[j]]==0){dp[i]=1;break;}
            else if(i>=arr[j]){;}
            else{break;}
        }
    }
    if(dp[k]){cout<<"First";}
    else{cout<<"Second";}
    return 0;
}
