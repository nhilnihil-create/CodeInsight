#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define Mod 1000000007
using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    // return in;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}

vector<ll> A,B,C;
vector<ll> dp[3];
ll solve(int n, int last)
{
	if(n<0)
		return 0;
	if(dp[last-1][n]!=-1)
		return dp[last-1][n];
	switch(last)
	{
		case 1: dp[last-1][n] = max(B[n]+solve(n-1,2),C[n]+solve(n-1,3));
				break;
		case 2: dp[last-1][n] = max(A[n]+solve(n-1,1),C[n]+solve(n-1,3));
				break;
		case 3: dp[last-1][n] = max(B[n]+solve(n-1,2),A[n]+solve(n-1,1));
				break;
	}
	return dp[last-1][n];
}

int main()	
{
	#ifdef SANS
		freopen("ongoingin.txt","r",stdin);
		freopen("ongoingout.txt","w",stdout);
	#endif
	fast
	int t=1;
	// cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		A.resize(n);
		B.resize(n);
		C.resize(n);
		for(int i=0; i<3; i++)
		{
			dp[i].resize(n);
			for(int j=0; j<n; j++)
				dp[i][j]=-1;
		}
		for(int i=0; i<n; i++)
			cin>>A[i]>>B[i]>>C[i];
		ll tempa=solve(n-1,1), tempb=solve(n-1,2), tempc=solve(n-1,3);
		cout<<max(tempa,max(tempb, tempc))<<endl;
	}
	#ifdef SANS
		cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
	#endif
}