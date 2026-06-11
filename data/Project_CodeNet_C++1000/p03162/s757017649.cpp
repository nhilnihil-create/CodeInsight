#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long int> dp1(n+1,0),dp2(n+1,0),dp3(n+1,0);
    vector<long long int> arr1(n+1,0),arr2(n+1,0),arr3(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>arr1[i]>>arr2[i]>>arr3[i];
    }
    dp1[1]=arr1[1];
    dp2[1]=arr2[1];
    dp3[1]=arr3[1];
    for(int i=2;i<=n;i++)
    {
        dp1[i]=arr1[i]+max(dp2[i-1],dp3[i-1]);
        dp2[i]=arr2[i]+max(dp1[i-1],dp3[i-1]);
        dp3[i]=arr3[i]+max(dp1[i-1],dp2[i-1]);
    }
    cout<<max(dp1[n],max(dp2[n],dp3[n]));
}