#include <bits/stdc++.h>
using namespace std;

int b[30];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m,c;
    cin>>n>>m>>c;

    for(int i=0;i<m;i++)cin>>b[i];

    int cnt=0;

    for(int i=0;i<n;i++)
    {
        int sum=0;
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            sum+=a*b[j];
        }

        if(sum+c>0)cnt++;
    }

    cout<<cnt<<"\n";

    return 0;
}
