#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,c;
    cin>>n>>m>>c;
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int ans=0;
    while(n--)
    {
        int temp=0;
        for(int i=0;i<m;i++)
        {
            int a;
            cin>>a;
            temp+=a*b[i];
        }
        temp+=c;
        if(temp>0)
        ans++;
        
    }
    cout<<ans<<"\n";

    
}