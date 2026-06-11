#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);
int n;
int arr[100001];
int cost[100001];

int func(int index)
{
    if(index>=n-1)
        return 0;
    if(cost[index]!=-1)
        return cost[index];


    if(index+1<=n-1 && index+2<=n-1)
    {
        return cost[index]=min(abs(arr[index]-arr[index+1])+func(index+1),abs(arr[index]-arr[index+2])+func(index+2));
    }

    else if(index+1<=n-1)
    {
        return cost[index]=abs(arr[index]-arr[index+1])+func(index+1);
    }


}
int main()
{
    optimize();

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    memset(cost,-1,sizeof(cost));

    int res=func(0);
    cout<<res<<endl;
}

