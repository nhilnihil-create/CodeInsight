#include<bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define ll long long 
#define pb push_back
#define mk make_pair
#define x first
#define y second
#define deb(x) cout<< #x <<" "<<x<<"\n";
#define deb1(x,y) cout<< #x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define sz(a) (int)a.size()
const ll MOD=1e9+7;
const int MAX=1e3;
const int MAX2=1025;
const ll inf=LLONG_MAX;
const double EPS=1e-6;
int dcmp(double x,double y)
{return (fabs(x-y)<=EPS)?0:(x<y)?1:-1;}
void init(){
	ios
	///cout << fixed << setprecision(15);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main()
{	init();
	int l;
	cin>>l;
	vector<int>s;
	for(int i=0;i<25;i++)
		if((l&(1ll<<i))!=0)
		s.pb(i);
	int node,edge;
	node=s[sz(s)-1]+1;
	edge=2*(node-1)+sz(s)-1;
	cout<<node<<" "<<edge<<"\n";
	for(int i=1;i<node;i++)
	{
		cout<<i<<" "<<i+1<<" "<<0<<"\n";
		cout<<i<<" "<<i+1<<" "<<(1ll<<(i-1))<<"\n";
	}
	int x=(1ll<<s[sz(s)-1])-1;
	for(int i=0;i<sz(s)-1;i++)
	{

		cout<<1+s[i]<<" "<<node<<" "<<(x+1)<<"\n";
		x+=(1<<s[i]);
	}

	
	
	


}
