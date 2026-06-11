#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<vector<double>>> dp(310,vector<vector<double>> (310,vector<double>(310,-1)));

double susi(int i,int j,int k)
{
    if(i == 0 && j ==0 && k ==0) return 0;
    if(i<0||j<0||k<0) return 0;

    if(dp[i][j][k] >0 )return dp[i][j][k];
    double ans = n + i*susi(i-1,j,k) + j*susi(i+1,j-1,k) + k*susi(i,j+1,k-1);
    return dp[i][j][k]=ans/(i+j+k);
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>n;
    vector<int> arr(4,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[a]++;
    }
    //cout<<arr[1]<<arr[2]<<arr[3];
    cout<<fixed<<setprecision(13)<<susi(arr[1],arr[2],arr[3])<<'\n';
}
