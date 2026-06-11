#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main(void)
{
    int c,n,m,t;

    cin>>n>>m>>c;

    int b[m];

    for (int i = 0; i <m; i++)
        cin >> b[i];

    int cont=0;

    for(int i=0;i<n; i++)
    {
        int ans=0;
        for(int j=0;j<m; j++)
        {
            cin>>t;
            ans=ans+t*b[j];
        }
        if(ans+c>0)
            cont++;

    }
    cout<<cont;
    return 0;
}
