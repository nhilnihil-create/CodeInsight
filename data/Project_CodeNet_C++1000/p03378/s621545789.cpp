#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(x<k)
            ++ans;
    }
    cout<<min(ans,m-ans);;
    return 0;
}

