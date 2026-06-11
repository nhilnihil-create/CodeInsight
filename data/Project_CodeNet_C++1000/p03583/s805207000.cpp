#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_poizcy.hpp>
typedef long long  ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define se second
#define por(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
 
 
using namespace std;
//using namespace __gnu_pbds;
typedef double lldb;
typedef pair<ll, ll>  ii;
typedef pair<double, ii>  iii;
typedef pair<double, double>  iidb;
typedef vector<ll>     vi;
typedef vector<vi>     vvi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = 1e9+7;
const double PI = acos(-1);
#define initseg ll new_nodo=(pnodo*2),mid=(iz+der)/2;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tam 3600
#define offset 3000
#define ptr nodo*
const ll MOD=1e9+7;

using namespace std;


int main()
{	
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin>>n;
	forr(a,1,tam)
	{
		forr(b,1,tam)
		{
			ll num1=4*a*b-n*a-n*b;
			ll num2=n*a*b;
			if (num1<=0)continue;
			if (num2%num1==0)
			{
				cout<<num2/num1<<" "<<a<<' '<<b<<endl;
				return 0;
			}
		}
	}
}			