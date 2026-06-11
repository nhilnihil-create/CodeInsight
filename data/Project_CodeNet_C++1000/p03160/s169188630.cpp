/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> ans(n,INT_MAX);
    ans[0]=0;
    for(int i=1;i<n;i++)
    {
        ans[i]=min(ans[i],ans[i-1]+abs(a[i]-a[i-1]));
        if(i-2>=0)
            ans[i]=min(ans[i],ans[i-2]+abs(a[i]-a[i-2]));
        
    }
    cout<<ans[n-1];
    return 0;
}
