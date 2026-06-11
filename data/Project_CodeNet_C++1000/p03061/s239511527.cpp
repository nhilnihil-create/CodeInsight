// Author : Hardik Upadhyay
// college: SVNIT 
// slogan : Ab to phod dunga
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,a,b) for(int i = a ; i >= b; i--)
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define sq(a) (a)*(a)
#define nl "\n"
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,
//tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
const int MAXN = 100005;
ll mod=1000000007;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi a(n);
	vi gcd_before_me(n),gcd_after_me(n);
	rep(i,0,n-1){
		cin>>a[i];
	}
	gcd_after_me[n-2] = a[n-1];
	rrep(i,n-3,0){
		gcd_after_me[i] = __gcd(gcd_after_me[i+1],a[i+1]);
	}
	gcd_before_me[1] = a[0];
	rep(i,2,n-1){
		gcd_before_me[i] = __gcd(gcd_before_me[i-1],a[i-1]);
	}
	int mx = gcd_after_me[0];
	mx = max(mx,gcd_before_me[n-1]);
	rep(i,1,n-2){
		int  x = __gcd(gcd_before_me[i],gcd_after_me[i]);
		if(x > mx){
			mx =  x;
		}
	}
	cout<<mx<<nl;
	return 0;
}
