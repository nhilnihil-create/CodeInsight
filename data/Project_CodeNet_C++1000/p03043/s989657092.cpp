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
    ll n,k,j;
    cin>>n>>k;
    long double sum=0;
    for(ll i=1;i<=n;i++)
    {
        j=0;
        while((i<<j)<k)
        {
            j++;
        }
      //  cout<<j<<" ";
        sum+=pow(0.5,j);
    }

  //  if(k<=n)
    //{
      //  sum+=(n-k+1);

    //}
    sum=sum/n;
    cout<<fixed<<setprecision(9)<<sum<<endl;
	return 0;
}
