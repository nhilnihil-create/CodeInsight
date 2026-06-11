#include <iostream>
#include <fstream>
#define SM 500
using namespace std;
long long n,S[SM],F[SM][SM],a[SM];
int main()
    {
        long long i,j,d=0,mid=0;
        cin>>n;
        for (i=1;i<=n;i++)
            for (j=i;j<=n;j++) F[i][j]=1e18;
        for (i=1;i<=n;i++)
        {
            cin>>a[i];
            S[i]=S[i-1]+a[i];
            F[i][i]=0;
        }
        for (d=1;d<=n-1;d++)
            for (i=1;i<=n-d;i++)
            {
                j=i+d;
                for (mid=i;mid<j;mid++)
                    F[i][j]=min(F[i][j],F[i][mid]+F[mid+1][j]);
                F[i][j]=F[i][j]+S[j]-S[i-1];
            }
        cout <<F[1][n];
        return 0;
    }
