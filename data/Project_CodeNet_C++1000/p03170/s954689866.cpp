/*input
1 100000
1
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


long long int minimum = 100000000000000;

int gcd(long long int a,long long int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 

struct ct_s_h {long long int cts, cth, index;};

bool compare(long long int a, long long int b) {
	if(gcd(a,b) < minimum)
		return 1;
	else return 0;
}




vector <ll> dp;

int main(){
	ll n,k; cin>>n>>k;
	vll a(n,0); rep(i,n)cin>>a[i];
	repA(i,0,k){dp.pb(0);}
	repA(i,0,k){
		rep(j,a.size()){
			if(i-a[j]>=0 && dp[i-a[j]]==0)
				dp[i]=1;
		}
	}
	if(dp[k])cout<<"First\n";
	if(dp[k]==0)cout<<"Second\n";
	return 0;	
}















 
