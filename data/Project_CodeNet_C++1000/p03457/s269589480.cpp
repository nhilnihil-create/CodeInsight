#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;cin>>n;

    bool ans=true;

    int x=0;
    int y=0;
    int t=0;

    for(int i=0;i<n;i++)
    {
        int it,ix,iy;
        cin>>it>>ix>>iy;

        int tt=it-t;
        int dd=abs(x-ix)+abs(y-iy);

        if(tt==dd||(tt>dd&&abs(dd-tt)%2==0))
        {
            x=ix;
            y=iy;
            t=it;
        }
        else
        {
            ans=false;
        }
    }

    puts(ans?"Yes":"No");

    return 0;
}
