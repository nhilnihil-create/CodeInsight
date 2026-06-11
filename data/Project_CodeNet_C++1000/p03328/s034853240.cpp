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
int mod = 998244353;

int32_t main()
{   fastio;

    int a , b;
    cin>>a>>b;

    int arr[1000];
    int cnt=1;
    arr[0]=0;
    map<int , int>mp;
    for(int i=1; i <= 999; i++)
    {
        arr[i]=cnt+arr[i-1];
        cnt++;
        mp[arr[i]]=i;
    }

    for(int i=0; i <= 499500; i++)
    {
        if(mp.find(a+i) != mp.end() && mp.find(b+i) != mp.end())
        {
            if(mp[a+i]+1 == mp[b+i]) {
                cout<<i<<endl;
                return 0;
            }
        }
    }

}
