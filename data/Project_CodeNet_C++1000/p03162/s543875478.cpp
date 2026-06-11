#include<bits/stdc++.h>
using namespace std;

int arr[100005][4];
int dp[100005][4], n;

int solve(int day, int flag)
{
    if(day==n)
        return 0;
    if(dp[day][flag] != -1)
        return dp[day][flag];

    int maxo = 0;

    if(flag == 0)
    {
        maxo = max(maxo, arr[day][1] + solve(day+1, 1));
        maxo = max(maxo, arr[day][2] + solve(day+1, 2));
        maxo = max(maxo, arr[day][3] + solve(day+1, 3));
    }
    else if(flag == 1)
    {
        maxo = max(maxo, arr[day][3] + solve(day+1, 3));
        maxo = max(maxo, arr[day][2] + solve(day+1, 2));
    }
    else if(flag == 2)
    {
        maxo = max( maxo , arr[day][1] + solve(day+1, 1));
        maxo = max(maxo , arr[day][3] + solve(day+1, 3));
    }
    else
    {
        maxo = max(maxo, arr[day][1] + solve(day+ 1, 1));
        maxo = max(maxo , arr[day][2] + solve(day+1, 2));
    }

    return dp[day][flag] = maxo;
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    
    cin>>n;

    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++)
        for(int j = 1; j<=3; j++)
            cin>>arr[i][j];


    cout<<solve(0 , 0)<<endl;


    return 0;
}
