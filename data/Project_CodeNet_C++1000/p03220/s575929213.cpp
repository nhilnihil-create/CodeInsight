#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double t;
    cin>>t;
    double a;
    cin>>a;

    double h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int ans=0;
    double diff = INT_MAX;
    for(int i=0;i<n;i++)
    {
        double temp = t-h[i] *0.006;
        double temp2 = abs( a- temp);

        if( temp2 < diff )
        {
            ans = i;
            diff= temp2;
        }
    }
    cout<<ans+1;
}