#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rapido ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"

void solve()
{
    vector<int>arr(3);
    for(int i=0;i<3;i++)
    cin>>arr[i];
    
    sort(arr.begin(),arr.end());
    int ans=(arr[0]*arr[1])/2;
    cout<<ans<<endl;
}
int32_t main()
{
    rapido;
    int t;
    // cin>>t;
    t=1;
    while(t--)
    solve();
}