#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);
int n,k;
int arr[100001];
int cost[100001];

int func(int index)
{
    if(index>=n-1)
        return 0;
    if(cost[index]!=-1)
        return cost[index];

    int step=INT_MAX;

    for(int jump=1; jump<=k; jump++)
    {
        if(index+jump<=n-1)
        {
            step=min(step,abs(arr[index]-arr[index+jump])+func(index+jump));
        }

    }

    return cost[index]=step;


}
int main()
{
    optimize();

    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    memset(cost,-1,sizeof(cost));

    int res=func(0);
    cout<<res<<endl;
}

