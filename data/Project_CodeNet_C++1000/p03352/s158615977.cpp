#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x;
    cin>>x;

    int ma=1;

    for(int i=2;i<sqrt(x);i++)
    {
        int n=i;
        for(int j=0;j<10;j++)
        {
            n*=i;
            if(n>x)break;
            ma=max(ma,n);
        }
    }

    cout<<ma<<"\n";

    return 0;
}
