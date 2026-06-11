/*input
5
0.42 0.01 0.42 0.99 0.42
*/
 
 
#include <bits/stdc++.h>
using namespace std;
 
#define ld long double
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define vpll vector < pair<long long,long long> >
#define fill(a,val)  memset(a,val, sizeof (a))
#define sort_unique(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define mp make_pair
#define pb push_back
#define f first
#define se second
#define all(cont) cont.begin(), cont.end()
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define INTMAX  2147483647
#define INTMIN  -2147483648
#define LLMAX 9223372036854775807
#define LLMIN -9223372036854775808
#define MOD 1000000007
typedef map<long long int, long long int> mpi;
typedef set<long long int> seti;
typedef multiset<long long int> mseti;
typedef priority_queue<long long int> pq;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define rep(i, n)    for(long long int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(ll i = a; i <= (n); ++i)
#define repD(i, a, n)  for(ll i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define repn(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define PI 3.1415926535
#define dbg(x) cerr << "\n" << (#x) << " = " << (x) << endl ;
//#define cerr if(false)cerr

// cout<<fixed<<setprecision(10)<<(v1+v2+v3)<<endl;
  
struct node{
    ll val;
};
struct Interval {int start, end;};
bool compare(struct node n1, struct node n2) {
    return (n1.val < n2.val);
}




long double dp[3000][3000];

int main(){
	ll n; cin>>n;
	vector <long double> p(n,0);
	rep(i,n)cin>>p[i];
	dp[0][1] = 1-p[0];
	dp[1][1] = p[0];
	for(int j=2;j<=n;j++){
		for(int i=0;i<=j;i++){
			if(i==j)
				dp[i][j] = dp[i-1][j-1]*p[j-1];
			else if(i==0)
				dp[i][j] = dp[i][j-1]*(1-p[j-1]);
			else
				dp[i][j] = dp[i-1][j-1]*p[j-1] + dp[i][j-1]*(1-p[j-1]);
		}
	}
	// for(int j=1;j<=n;j++){
	// 	for(int i=0;i<=j;i++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	long double ans = 0.0;
	for(int i=(n/2+ 1);i<=n;i++){
		ans+=dp[i][n];
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;
	return 0;	
}















 