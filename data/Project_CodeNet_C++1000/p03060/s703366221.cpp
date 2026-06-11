#include<bits/stdc++.h>
using namespace std;


int go(int val[1000],int cost[1000],int x,int y,int num,int n)
{

    int mini=0;

    if(num==n)
    {
        return max(mini,(x-y));
    }



    num++;
    mini=max(mini,go(val,cost,x,y,num,n));

    num--;
    x=x+val[num];
    y=y+cost[num];
    num++;
    mini=max(mini,go(val,cost,x,y,num,n));

    return mini;





}



int main()
{
    int n;
    cin>>n;
    int val[1000];
    int cost[1000];


    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>cost[i];
    }

    int mini=0;

    int x=0;
    int y=0;

    int num=0;


    num++;
    mini=max(mini,go(val,cost,x,y,num,n));

    num--;
    x=x+val[num];
    y=y+cost[num];
    num++;
    mini=max(mini,go(val,cost,x,y,num,n));

    cout<<mini<<endl;






}
