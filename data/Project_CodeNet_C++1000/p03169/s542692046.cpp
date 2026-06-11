/*
    author : Divyansh Gupta
*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <map>

using namespace std;

void print_err() {
	cerr<<"\n";
}

template <class T,class... Arg>
void print_err(T x,Arg&&... args) {
	cerr<<x<<" ";
	print_err(args...);
}

#ifdef local
#define debug(...) print_err(__VA_ARGS__)
#else
#define debug(...)
#endif

#define test_case int test_cases;\
                cin>>test_cases;\
                while(test_cases--)
#define lu(var,l,r) for(var=l;var<r;var++)
#define ld(var,r,l) for(var=r;var>=l;var--)
#define ll long long
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>                	
#define br cout<<"\n"
#define sp cout<<" "
#define pr cout<<
#define in cin>>
#define f first
#define s second                    
#define mod 1000000007
            
double expected(int n,int x,int y,int z,vi &A,vector<vector<vector<double> > > &dp) {
	if(x == 0 && y == 0 && z == 0) {
		return 0;
	}
	if(x < 0 || y < 0 || z < 0) {
		return 0;
	}
	if(dp[x][y][z] > -0.9) {
		return dp[x][y][z];
	}
	double ways = n + x * expected(n,x-1,y,z,A,dp) + y * expected(n,x+1,y-1,z,A,dp) + z * expected(n,x,y+1,z-1,A,dp);
	return dp[x][y][z] = ways / (x + y + z);
}

void solve(){
	int n,x,i;
	vi A,X(4,0);
	A.pb(0);
	in n;
	lu(i,1,n+1) {
		in x;
		A.pb(x);
		X[x]++;
	}
	vector<vector<vector<double> > > dp(301,vector<vector<double> >(301,vector<double>(301,-1.0)));
	pr setprecision(14)<<expected(n,X[1],X[2],X[3],A,dp);
	br;
}

int main(){
    // test_case
    solve();
    return 0;
}