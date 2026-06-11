#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y,i,xx[200],yy[200];
    cin>>n>>m>>x>>y;
    for(i=0;i<n;i++)
        cin>>xx[i];
    for(i=0;i<m;i++)
        cin>>yy[i];
    sort(xx,xx+n);
    sort(yy,yy+m);
    for(i=x+1;i<=y;i++)
    {
        if(i>xx[n-1]&&i<=yy[0])
        {
            cout<<"No War"<<endl;
            return 0;
        }
    }
    cout<<"War"<<endl;
    return 0;
}
