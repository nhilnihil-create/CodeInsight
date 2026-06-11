#include <bits/stdc++.h>

#define INF 214000000
#define MOD 998244353
#define MaxN 1005

using namespace std;

/*#ifdef INFOARENA
FILE* IN=fopen("bacterii2.in","r"), *OUT=fopen("bacterii2.out","w");
#else
FILE* IN=fopen("test.in","r"), *OUT=fopen("test.out","w");
#endif*/

int N,M,Mat[MaxN][MaxN];

int main()
{
    M=1;
    cin>>N;
    while(M*(M-1)/2<N)
        M++;
    if(M*(M-1)/2!=N)
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n"<<M<<'\n';
        for(int i=1;i<=M;i++)
        {
            Mat[i][0]=M-1;
        }
        for(int i=2;i<=M;i++)
        {
            int x=i*(i-1)/2;
            for(int j=i-1;j>0;j--)
            {
                Mat[i][j]=x;
                x--;
            }
            Mat[i-1][i-1]=Mat[i][i-1];
            for(int j=i-2;j>0;j--)
                Mat[j][i-1]=Mat[j+1][i-1]-1;
        }
        for(int i=1;i<=M;i++)
        {
            for(int j=0;j<M;j++)
                cout<<Mat[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}
