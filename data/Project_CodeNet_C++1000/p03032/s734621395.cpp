#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[60], k, ans;
vector<int> v[60][60];
int main()
{
    IO
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
        {
            for(int ii=1; ii<=i; ii++)
                v[i][j].push_back(a[ii]);
            for(int ii=n; ii>=n-j+1; ii--)
                v[i][j].push_back(a[ii]);
            sort(v[i][j].begin(),v[i][j].end());
        }
    for(int i=0; i<=k; i++)
        for(int j=0; j<=k; j++)
            for(int r=0; r<=k; r++)
            {
                if(i+j+r>k || i+j>n || r>i+j)
                    continue;
                int sum=0;
                for(auto t : v[i][j])
                    sum+=t;
                for(int t=0; t<r; t++)
                    sum-=v[i][j][t];
                ans=max(ans,sum);
            }
    cout<<ans;

}
