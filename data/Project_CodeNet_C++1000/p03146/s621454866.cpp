#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int,int>tack;
    int n;
    cin>>n;
    tack[n]++;
    int count=1;
    while(1)
    {
    count++;
    if(n%2==0)
    {
        n=n/2;
        if(tack[n]!=0)
        {
            cout<<count<<"\n";
            return 0;
        }
        else
        tack[n]++;
    }
    else
    {
        n=n*3+1;
        if(tack[n]!=0)
        {
            cout<<count<<"\n";
            return 0;
        }
        else
        tack[n]++;
    }

    }
    
}