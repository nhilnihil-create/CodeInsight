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
    int n;
    cin>>n;
    ll x=n/100;
    ll y=n%100;
    if(y>0 && y<=12)
    {
        if(x>0 && x<=12)
        {
            cout<<"AMBIGUOUS";
        }
        else
        {
            cout<<"YYMM";
        }
    }
    else
    {
        if(x>0 && x<=12)
        {
            cout<<"MMYY";
        }
        else
        {
            //cout<<"YYMM";
            cout<<"NA";
        }
    }

	return 0;
}
