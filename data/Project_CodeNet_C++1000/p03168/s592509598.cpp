#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define infin ll (pow(10,9)+7);
typedef unsigned int ui;
int main()
{
    int n;
    cin>>n;
    double p[n+1][n+1];
    double given[n+1];
    for(int i=1;i<=n;i++)
        cin>>given[i];
    p[1][0]=1-given[1];
    p[1][1]=given[1];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if (j==0)
               p[i][j]=p[i-1][j]*(1-given[i]);
            else if(i-1<j)
              p[i][j]=p[i-1][j-1]*given[i];

            else
            {
                p[i][j]=p[i-1][j]*(1-given[i])+(p[i-1][j-1]*given[i]);
            }
            
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=0;j<=i;j++)
    //     cout<<i<<" "<<j<<"  "<<p[i][j]<<endl;
    // }
    double answer=0.0;
    for(int i=floor(n/2)+1;i<=n;i++)
    {
        answer=answer+p[n][i];
    }   
    cout<<setprecision(10)<<answer<<endl;
}