#include<bits/stdc++.h>
#include <iomanip>
using namespace std;





int main()
{
    int n,k;
    cin>>n>>k;

    bool dp[k+1];

    for(int i=0; i<=k; ++i)
    {
        dp[i] = false;
    }
    vector<int> arr(n);

    for(int i=0; i<n; ++i)
    {

        cin>>arr[i];

    }


    for(int i=1; i<=k; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(arr[j]<=i)
            {
                dp[i] = !(dp[i-arr[j]]);
                if(dp[i])
                {
                    break;
                }
            }
        }
    }




    if(dp[k])
    {
        cout<<"First"<<endl;
    }
    else
    {
        cout<<"Second"<<endl;
    }




    return 0;

}
