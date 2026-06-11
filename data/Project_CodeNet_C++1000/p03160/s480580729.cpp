//God's Grace
#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#include <list>
#include <string>
#include <cmath>
#include <stack>
#include <cstdio>
#include <fstream>
#include <climits>
#include <set>
#include <vector>
#include <tuple>
#include <cstring>
#include <functional>
#include <utility>
#include <iomanip>

using namespace std;

#define endl '\n'
#define f(k,a,b) for(int k=(a);k<(b);k++)
#define vi vector <int>
#define vvi vector <vector <int> >
#define vii vector <pair <int, int > >
#define int long long
#define lli long long
#define pii pair <int,int>
#define piii pair< pair<lli,lli>, lli >
#define fsd fflush(stdout);
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
//#define tdef typedef
#define ret return
const int fix = (int)1e9 + 7;

int po2(lli a){double temp = a;if(log2(temp)==(int)log2(temp))return log2(temp);return -1;}
void tc(int i){cout<<"Case #"<<i+1<<": ";}
void yes(){cout<<"YES"<<endl;}
void no(){cout<<"NO"<<endl;}
void impb(){cout<<"IMPOSSIBLE"<<endl;}
int ct(){int t;scanf("%lld",&t);return t;}
int gcd(int a, int b) {if (b == 0)return a;return gcd(b, a % b);}
int pwr(int a, int b){ int x=1, y=a; while(b>0){if(b%2) x = (x*y)%fix; y=(y*y)%fix; b/=2;} return x;}
void error(){cerr<<"Here!"<<endl;}

/*
lli modinv(lli a, lli m){
	lli m0 = m;
	lli y = 0, x = 1;

	    if (m == 1)
	      return 0;

	    while (a > 1)
	    {
	        // q is quotient
	       lli q = a / m;
	       lli t = m;

	        // m is remainder now, process same as
	        // Euclid's algo
	        m = a % m, a = t;
	        t = y;

	        // Update y and x
	        y = x - q * y;
	        x = t;
	    }

	    // Make x positive
	    if (x < 0)
	       x += m0;

	    return x;

}

*/

int pmodinv(int a){
	return pwr(a,fix-2);
}

//int arr[(int)5e5+5];
const int N = 5e5+5;
list <int> adj[N];
queue <int> q;

int comanc(int u, int v,int parent[]){
	while(u^v){
		if(u==1||v==1)
			return 1;
		u = parent[u];
		v = parent[v];
	}

	return u;
}
int x;

int max(int a, int b){
	if (a>b)
		return a;
	return b;
}

vector <int> factorial((int)4002);

int nCr(int n, int k){
	return (factorial[n]*((pmodinv(factorial[k])*pmodinv(factorial[n-k]))%fix))%fix;
}





int32_t main() {




	int t=1;
	//t=ct();


	f(ii,0,t){
		int n=ct();
		vi dp(n+1,INT_MAX);
		vi h(n+1);
		f(j,1,n+1)cin>>h[j];
		dp[1]=0;
		dp[2] = abs(h[2]-h[1]);
		f(j,3,n+1){

			dp[j] = min(dp[j], min(dp[j-2] + abs(h[j]-h[j-2]),dp[j-1] + abs(h[j]-h[j-1])));
		}

		printf("%lld\n",dp[n]);
	}
	ret 0;
}
