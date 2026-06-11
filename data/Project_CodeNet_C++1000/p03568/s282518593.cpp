#include <bits/stdc++.h>
using namespace std;

int a[10];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>a[i];

    int b=1;
    int c=1;

    for(int i=0;i<n;i++)
    {
        b*=3;
        if(a[i]%2==0)c*=2;
    }

    cout<<b-c<<"\n";

    return 0;
}
