#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y,ans=0;
    cin>>n>>x>>y;
    while(n--)
    {
        int X,Y;
        cin>>X>>Y;
        if(X>=x&&Y>=y)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
