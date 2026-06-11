#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x;
    cin>>x;
    int y[x];
    for (int i=0; i<x; i++)
        cin>>y[i];
    int a[x]= {},ans=0;
    while (1)
    {
        int cnt=0;
        for (int i=0; i<x; i++)
        {
            if (a[i]==y[i])
            {
                if (cnt)
                {
                    ans++;
                    for (int j=i-cnt; j<i; j++)
                        a[j]++;
                }
                cnt=0;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt)
        {
            ans++;
            for (int j=x-cnt; j<x; j++)
                a[j]++;
        }
        bool end=1;
        for (int i=0; i<x; i++)
            if (a[i]!=y[i])
                end=0;
        if (end)
            break;
    }
    cout<<ans;
    return 0;
}
