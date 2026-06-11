#include<bits/stdc++.h>
using namespace std;

int vacationpoints(int n,int activities[][3])
{
    if(n==1)
        return max(activities[0][0],max(activities[0][1],activities[0][2]));
    //int activities[n][3];
    
    for(int i=0;i<n;i++)
    {
        // activities[i][0]=activities[i][0];
        // activities[i][1]=activities[i][1];
        // activities[i][2]=activities[i][2];
        if(i>0)
        {
            activities[i][0]+=max(activities[i-1][1],activities[i-1][2]);
            activities[i][1]+=max(activities[i-1][0],activities[i-1][2]);
            activities[i][2]+=max(activities[i-1][0],activities[i-1][1]);
        }
    }
    // for(int j=0;j<n;j++)
    // {
    //     for(int i=0;i<3;i++)
    //         cout<<activities[j][i]<<" ";
    //     cout<<endl;
    // }
    return max(activities[n-1][0],max(activities[n-1][1],activities[n-1][2]));
}


int main()
{
    int n;
    cin>>n;
    int activities[n][3];
    for(int j=0;j<n;j++)
        for(int i=0;i<3;i++)
            cin>>activities[j][i];
    cout<<vacationpoints(n,activities)<<endl;
}