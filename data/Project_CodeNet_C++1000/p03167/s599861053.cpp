#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define infin ll (pow(10,9)+7);
int main()
{
    int h,w;
    cin>>h>>w;
    ll ways[h][w] ;//ways[i][j]=no.of ways to reach (h-1,w-1) from i,j 
    char given[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>given[i][j];
        }
    }
    ways[h-1][w-1]=1;
    for(int j=w-2;j>=0;j--)
    {
        if (given[h-1][j]=='#')
            ways[h-1][j]=0;
        else
        {
            //cout<<j<<" "<<ways[h-1][j+1]<<endl;
            ways[h-1][j]=(ways[h-1][j+1]) % infin;
            //cout<<ways[h-1][j]<<endl;
        }
    }
    for(int i=h-2;i>=0;i--)
    {
        if (given[i][w-1]=='#')
            ways[i][w-1]=0;
        else
            ways[i][w-1]=(ways[i+1][w-1]) % infin;
    }
    //cout<<"all good"<<endl;
    // for(int i=0;i<h;i++)//just print
    //    {
    //       for(int j=0;j<w;j++)
    //         cout<<ways[i][j]<<" ";
    //       cout<<endl;
    //     }
    
    for(int i=h-2;i>=0;i--)
    {
        for(int j=w-2;j>=0;j--)
        {
            if (given[i][j]=='#')
                ways[i][j]=0;
            else
                ways[i][j]=(ways[i+1][j]+ways[i][j+1]) % infin;
        }
    }
    // cout<<"\n\n"<<endl;
    // for(int i=0;i<h;i++)
    //    {
    //       for(int j=0;j<w;j++)
    //         cout<<ways[i][j]<<" ";
    //       cout<<endl;
    //     }
    cout<<ways[0][0]<<endl;

}
