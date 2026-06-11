#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,t,a,b,n,c,d,y,temp,m,r,sum,count,k,l,ans;
    t=1;
    // cin>>t;
    while(t--)
    {
        char ch[2][3];
        for(i=0;i<2;i++)
        for(j=0;j<3;j++)
        cin>>ch[i][j];
        {
            if(ch[0][0]==ch[1][2] && ch[0][2]==ch[1][0] && ch[0][1]==ch[1][1])
                cout<<"YES";
            else cout<<"NO";
        }
        
    }
}