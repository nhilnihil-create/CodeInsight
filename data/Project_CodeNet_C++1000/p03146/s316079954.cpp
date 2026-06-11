#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,ans=0;
    set<int>s;
    cin>>n;
    while(1)
    {
        ++ans;
        if(s.count(n)==0)
        s.insert(n);
        else
            break;
        if(n%2==0)
        {
            n=n/2;
        }
        else
        {
            n=3*n+1;
        }
    }
    cout<<ans;
    return 0;
}

