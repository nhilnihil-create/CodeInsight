#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n,x,ans=100;
        cin>>n;
        while(n--)
        {
            cin>>x;
            int i;
            for(i=0;i<32;i++)
            {
                if(x&1<<i)
                {
                    break;
                }
            }
            ans=min(i,ans);
        }
        cout<<ans;

}

