#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define PB push_back
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int arr[100000][3];
int n;
int dp[100000][3];
int rec(int row, int col)
{
    if(row == n-1)  return arr[n-1][col];
    if(dp[row][col]>0)
        return dp[row][col];
    else if(col==0)
        return dp[row][col]=arr[row][col]+max(rec(row+1,1),rec(row+1,2));
    else if(col==1)
        return dp[row][col]=arr[row][col]+max(rec(row+1,0),rec(row+1,2));
    else if(col==2)
        return dp[row][col]=arr[row][col]+max(rec(row+1,0),rec(row+1,1));
}

int main()
{
    optimize();

    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }
    int x=max(rec(0,0),max(rec(0,1),rec(0,2)));
    cout<<x;
    return 0;
}
