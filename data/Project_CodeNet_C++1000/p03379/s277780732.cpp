#include <bits/stdc++.h>
using namespace std;

int x[200010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;
    vector<int> y(n);
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        y[i]=x[i];
    }

    sort(y.begin(),y.end());

    for(int i=0;i<n;i++)
    {
        if(x[i]>=y[n/2])cout<<y[n/2-1]<<"\n";
        else cout<<y[n/2]<<"\n";
    }

    return 0;
}
