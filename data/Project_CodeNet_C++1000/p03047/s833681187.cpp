#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
//#include <boost/lexical_cast.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define pb push_back
#define mp make_pair
#define endl '\n'
#define PI acos(-1)
typedef tree<int,null_type,less_equal <int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

long mod=1e9+7;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,k;
	cin>>n>>k;
	cout<<((n-k+1>0)?n-k+1:0);
	return 0;
}