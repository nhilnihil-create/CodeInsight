#include <bits/stdc++.h>
using namespace std;

int suma,sumb;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end(),greater<int>());

    for(int i=0;i<n;i++)
    {
        if(i%2)sumb+=a[i];
        else suma+=a[i];
    }

    cout<<suma-sumb<<"\n";

    return 0;
}
