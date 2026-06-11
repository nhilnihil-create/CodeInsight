#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll m,k,nr;
int main()
{
    cin>>m>>k;
    nr=(1<<m)-1;
    if(k>nr)
    {
        cout<<-1;
        return 0;
    }
    if(m>=2)
    {
        for(int i=nr;i>=0;i--)
            if(i!=k)
                cout<<i<<" ";
        cout<<k<<" ";
        for(int i=0;i<=nr;i++)
            if(i!=k)
                cout<<i<<" ";
        cout<<k;
    }
    else if(m==0&&k==0)
    {
        cout<<"0 0";
    }
    else if(m==1)
    {
        if(k==0)
            cout<<"0 0 1 1";
        else
            cout<<-1;
    }
    return 0;
}
