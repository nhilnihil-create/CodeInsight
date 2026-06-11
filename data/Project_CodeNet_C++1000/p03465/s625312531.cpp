#include<iostream>
#include<bitset>

using namespace std;

bitset<2000005> Dp;
int A[2005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        cin>>A[i];
        sum+=A[i];
    }

    //fiecare submult de suma<=sum/2 are coresp o subsecventa din restul el de suma>=sum/2
    Dp[0]=1;
    for(int i=1; i<=n; i++)
    {
        if(A[i]<=sum/2)
            Dp=Dp|(Dp<<(A[i]));
    }

    int val=sum/2;
    while(!Dp[val])
        val--;

    cout<<sum-val<<"\n";
    return 0;
}
