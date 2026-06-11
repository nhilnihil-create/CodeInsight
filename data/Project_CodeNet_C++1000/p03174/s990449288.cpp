#include<bits/stdc++.h>
#define REP(i, a, b) for(long long i=a; i<=b; ++i)
#define REPN(i, a, b) for(long long i=a; i<=b; --i)
#define rep(i, a, b) for(long long i=a; i<b; ++i)
#define rep0(i,b) for(long long i=0; i<b; ++i)
#define REP0(i,b) for(long long i=0; i<=b; ++i)
#include<cmath>
#include <iomanip>
using namespace std;


typedef long long ll;

int MODE = 1e9+7;

ll dp[22][(1<<21)];
int arr[21][21];

int helper(int currentMan, int mask, int n)
{


    if(currentMan == n)
    {
        return 1;
    }
    if(dp[currentMan][mask] != -1)
    {

        return dp[currentMan][mask];
    }

    int total = 0;

    for(int i=0; i<n; ++i)
    {
         //cout<<arr[currentMan][i]<<"\t"<< (mask>>i & 1)<<endl;
        if(arr[currentMan][i] == 1 && ( (mask>>i) & 1 == 1))
        {
            int tempMask = mask ^ (1<<i);

            total += helper(currentMan + 1, tempMask, n);
            total %= MODE;
        }
    }


    return dp[currentMan][mask] = total;


}


int main()
{

    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    rep0(i, n)
    {
        rep0(j, n)
        {
            cin>>arr[i][j];
        }
    }






    int mask = (1<<n) - 1;

    cout<<helper(0, mask, n)<<endl;



    return 0;

}
