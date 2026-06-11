#include <bits/stdc++.h>
using namespace std;

long long q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>q;
    while(q--)
    {
        long long x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        if(x==y)
            cout<<2*x-2<<endl;
        else if(x==y-1)
            cout<<2*x-2<<endl;
        else
        {
            long long c=sqrt(x*y);
            if(c*c==x*y)
                c--;
            if(c*(c+1)>=x*y)
                cout<<2*c-2<<endl;
            else
                cout<<2*c-1<<endl;
        }
    }

    return 0;
}
