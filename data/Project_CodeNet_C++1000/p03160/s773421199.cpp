#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define PB push_back
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,k;
int arr[100005];
int dp[100005];

int f(int indx)
{
    if(indx>=n-1)
        return 0;

    if(dp[indx]!=-1)
        return dp[indx];
     int x=INT_MAX;
     for(int i=1;i<=2;i++)
     {
         if(indx+i<=n-1)
            x=min(x,abs( arr[indx]-arr[indx+i])+f(indx+i));
     }
    return dp[indx]=x;
}

int main()
{
    optimize();
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>arr[i];

   memset(dp,-1,sizeof(dp));
    cout<<f(0)<<endl;
    return 0;
}
