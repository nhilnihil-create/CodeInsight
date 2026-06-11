#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ax[202][102]= {0};
    a--,b--;
    for(int i=51; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            ax[i][j]=1;
        }
    }
    for(int i=1; i<50; i+=2)
    {
        for(int j=1; j<=100; j+=2)
        {
            if(a==0)
                break;
            ax[i][j]=1;
            a--;
        }
        if(a==0)
            break;
    }
    for(int i=52; i<=100; i+=2)
    {
        for(int j=1; j<=100; j+=2)
        {
            if(b==0)
                break;
            ax[i][j]=0;
            b--;
        }
        if(b==0)
            break;
    }
    cout<<100<<" "<<100<<endl;
    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=100; j++)
        {
            if(ax[i][j]==0)
                cout<<"#";
            else
                cout<<".";
        }
        cout<<endl;
    }
}
