#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x[n+5];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
    }
    sort(x,x+n);
    int sum=0;
    for(int i=0;i<n-1;i++)
    {
        sum+=x[i];
    }
    sum+=(x[n-1]/2);
    cout<<sum<<endl;
return 0;
}
