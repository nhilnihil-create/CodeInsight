#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , m;
    cin>>n>>m;
    int* likes = new int[m+1]();
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            int t;
            cin>>t;
            likes[t]++;
        }
    }
    int ans =0;
    for(int i=0;i<=m;i++)
    {
        if( likes[i] == n)
            ans++;
    }
    cout<<ans;
}