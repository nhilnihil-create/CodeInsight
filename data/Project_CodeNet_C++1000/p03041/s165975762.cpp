#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>


int main()
{
	ssd
	#define task "TASK"
	 //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(ll i=0;i<n;i++)
    {
        if(i==k-1)
        {
            cout<<((char)tolower(s[i]));
        }
        else
        {
            cout<<s[i];
        }
    }

	return 0;
}
