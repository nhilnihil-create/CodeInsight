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


long double power(double a, double b){
	if(b==0)return 1.0;
	long double res = 1;
	res = pow(a,b/2);
	res*=res;
	if((int)b%2==1){
		res*=a;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	double res = 0;
	double x = (double)1/n;
	bool f = 0;
	for(int i = 1; i <= n ; i++){
		double st = i;
		double tmp = x;
		while(st < k){
			st = st*2;
			tmp  = tmp/2;
		}	
		res+=(tmp);
	}
	printf("%.15f",res);
	return 0;
}
