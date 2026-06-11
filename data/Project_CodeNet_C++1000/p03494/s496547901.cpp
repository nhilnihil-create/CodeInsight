#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    ll ara[n];
    int flag=1;
    for(int i=0; i<n; i++)
    {
        cin>>ara[i];
        if(ara[i]%2) flag=0;
    }
    if(flag)
    {
        int cnt=0;
        while(flag)
        {
            for(int i=0; i<n; i++)
            {
                ara[i]/=2;
                if(ara[i]%2) flag=0;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    else
        cout<<0<<endl;

}
