#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r", stdin);
    //freopen("output.txt","w",stdout);
    int n,m; cin>>n>>m;
    m/=1000; bool b =false;
    int x=0,y=0,z=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(n-i-j<0) continue;
            int k = n-i-j;
            if(i+5*j+10*k==m)
            {
                x=i;y=j;z=k;
                b=true;
                break;
            }
        }
    }

    if(!b) cout<<-1<<" "<<-1<<" "<<-1;
    else cout<<z<<" "<<y<<" "<<x;
}