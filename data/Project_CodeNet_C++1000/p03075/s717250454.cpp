#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int a[5],k,i,j;
    for (i=0;i<5;i++)
        cin>>a[i];
    cin>>k;
    bool flag=true;
    for (i=0;i<4;i++)
    {
        for (j=i+1;j<5;j++)
        {
            if (a[j]-a[i]>k)
            {
                flag=false;
                break;
            }
        }
        if (flag==false)
            break;
    }
    if (flag)
        cout<<"Yay!\n";
    else
        cout<<":(\n";
}