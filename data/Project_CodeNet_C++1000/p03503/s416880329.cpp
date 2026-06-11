#include <bits/stdc++.h>

#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
typedef long double ld;
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
const int N=100+5, mxN=(1<<22);
int mod=1e9+7;
int n;
ll ans=-1e18;
int arr[N][11],cost[N][12];
void brutefor(int i, int mask)
{
    if(i==10)
    {
        if(mask==0)
            return;
  ll localans=0;
    for(int x=0;x<n;x++)
    {

        int co=0;
        for(int j=0;j<10;j++)
        {
            if(arr[x][j]==1&&((mask>>j)&1)==1)
            {
                co++;
            }

        }
        localans+=cost[x][co];

    }
    ans=max(ans,localans);



    }
    else
    {
        brutefor(i+1,mask);
        mask=(mask|(1<<i));
        brutefor(i+1,mask);



    }


}

int main()
{
    FIO
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>arr[i][j];
        }

    }

   for(int i=0;i<n;i++)
    {
        for(int j=0;j<=10;j++)
        {
            cin>>cost[i][j];
        }

    }
     brutefor(0,0);
     cout<<ans;


    return 0;

}



