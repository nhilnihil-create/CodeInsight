#include<bits/stdc++.h>
using namespace std;
int pos[200009],ans1[200009],ans2[200009];

int main()
{
    int i,j,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> j;
        pos[j]=i;
    }
    for(i=n-1;i>=1;i--)
    {
        if(pos[i]<pos[i+1])
            ans1[i]=ans1[i+1];
        else ans1[i] = (n-i);
    }
    for(i=2;i<=n;i++)
    {
        if(pos[i]>pos[i-1])
            ans2[i]=ans2[i-1];
        else ans2[i]=i-1;
    }
    int ans = n;
    for(i=1;i<=n;i++)
    {
        ans=min(ans,ans1[i]+ans2[i]);
    }
    cout << ans << endl;
}
