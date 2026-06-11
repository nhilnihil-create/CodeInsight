#include<bits/stdc++.h>
using namespace std;

int nai[200];

int main()
{
    int n,i,j,k;
    cin >> n;
    int half = n/2;

    for(i=half,j=half+1;i>=1;i--,j++)
        nai[i]=j;
    cout << n*(n-1)/2 - half << endl;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(nai[i]!=j) cout << i << ' ' << j << endl;
        }
    }
    return 0;
}
