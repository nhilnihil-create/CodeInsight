#include <bits/stdc++.h>

#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

typedef long long ll;
typedef long double ld;
using namespace std;
#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
const int N=2e5+5;
int mod=1e9+7;

int main()
{
    FIO
    int mod,n,arr[N];
    cin>>n>>mod;
    int sum=0;
    map<ll ,ll>mp;
    mp[0]++;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        sum%=mod;
        mp[sum]++;
    }
    ll ans=0;
    for(auto i:mp)
    {
        ans+=i.second*(i.second-1)/2;

    }
    cout<<ans;


    return 0;

}
