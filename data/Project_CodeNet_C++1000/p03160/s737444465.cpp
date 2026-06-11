#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define PB push_back
#define MP make_pair
#define endl '\n'
#define all(a) (a).begin(),(a).end()
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
int arr[100005];
int dp[100005];



int main()
{
    optimize();
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    dp[2]=abs(arr[1]-arr[2]);
    for(int i=3;i<=n;i++)
        dp[i]=min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));

    cout<<dp[n]<<endl;

    return 0;
}
