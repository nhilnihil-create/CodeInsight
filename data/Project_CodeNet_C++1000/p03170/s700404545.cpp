#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin>>a[i];

    vector<bool> dp(k+1);

    for(int stones=0; stones <= k; stones++)
    {
        for(int x : a)
        {
            if(stones >= x && dp[stones-x] == false)
                dp[stones] = true;
        }
    }

    if(dp[k])
        cout<<"First"<<endl;
    else
        cout<<"Second"<<endl;

    return 0;
} 
