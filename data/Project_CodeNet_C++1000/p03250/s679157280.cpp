#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define int long long
#define all(v) v.begin() , v.end()
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{   fastio;

    int arr[3];
    for(int i=0; i<3; i++)
        cin>>arr[i];
    sort(arr , arr+3);
    int p=arr[0];
    int j=arr[2]*10+arr[1]+arr[0];
    cout<<j<<endl;

}